-- This script is for initialization of the VISHNU Oracle 11g database
-- Script name          : oracle_create.sql
-- Script owner         : SysFera SAS

-- REVISIONS
-- Revision nb          : 1.0
-- Revision date        : 27/01/11
-- Revision author      : Benjamin Isnard <benjamin.isnard@sysfera.com>
-- Revision comment     : initial version
--
-- Revision nb          : 2.0
-- Revision date        : 31/08/2
-- Revision author      : Jean-Baptiste Ghoul <jean-baptiste.ghoul@sysfera.com>
-- Revision comment     : version for SOCI


drop table GlobProj cascade constraints;
drop table GlobProj_permissions cascade constraints;
drop table account cascade constraints;
drop table acl_class cascade constraints;
drop table acl_entry cascade constraints;
drop table acl_object_identity cascade constraints;
drop table acl_sid cascade constraints;
drop table application cascade constraints;
drop table application_parameter cascade constraints;
drop table application_version cascade constraints;
drop table authaccount cascade constraints;
drop table authsystem cascade constraints;
drop table clmachine cascade constraints;
drop table command cascade constraints;
drop table description cascade constraints;
drop table filetransfer cascade constraints;
drop table job cascade constraints;
drop table ldapauthsystem cascade constraints;
drop table machine cascade constraints;
drop table notification cascade constraints;
drop table optionu cascade constraints;
drop table optionvalue cascade constraints;
drop table parameter_value cascade constraints;
drop table permission cascade constraints;
drop table permission_module cascade constraints;
drop table process cascade constraints;
drop table project cascade constraints;
drop table project_application cascade constraints;
drop table project_machine cascade constraints;
drop table project_member cascade constraints;
drop table project_member_project_role cascade constraints;
drop table project_role cascade constraints;
drop table project_role_permissions cascade constraints;
drop table role cascade constraints;
drop table state cascade constraints;
drop table threshold cascade constraints;
drop table user_role cascade constraints;
drop table users cascade constraints;
drop table vishnu cascade constraints;
drop table vsession cascade constraints;
drop table work cascade constraints;
drop sequence hibernate_sequence;
drop sequence s_account;
drop sequence s_clmachine;
drop sequence s_command;
drop sequence s_description;
drop sequence s_filetransfer;
drop sequence s_job;
drop sequence s_machine;
drop sequence s_optionu;
drop sequence s_optionvalue;
drop sequence s_process;
drop sequence s_state;
drop sequence s_threshold;
drop sequence s_users;
drop sequence s_vishnu;
drop sequence s_vsession;
drop sequence s_work;

create table GlobProj (id number(19,0) not null, version number(19,0) not null, description clob, is_built_in number(1,0) not null, is_default number(1,0) not null, label varchar2(255 char) not null, member_specific number(1,0) not null, name varchar2(255 char) not null, pos number(19,0) not null, primary key (id));
create table GlobProj_permissions (global_project_role_id number(19,0), permissions_string varchar2(255 char));

create table account (numaccountid number(19,0) not null, aclogin varchar2(255 char), home varchar2(255 char), machine_nummachineid number(19,0) not null, sshpathkey varchar2(255 char), users_numuserid number(19,0) not null, primary key (numaccountid));
CREATE SEQUENCE s_account;

CREATE OR REPLACE TRIGGER AINC_account
BEFORE INSERT  ON account
FOR EACH ROW
BEGIN
  IF (:NEW.numaccountid IS NULL) THEN
    SELECT s_account.NEXTVAL INTO :NEW.numaccountid FROM DUAL;
  END IF;
END;
/
create table acl_class (id number(19,0) not null, class varchar2(255 char) not null, primary key (id));
create table acl_entry (id number(19,0) not null, ace_order number(10,0) not null, acl_object_identity number(19,0) not null, audit_failure number(1,0) not null, audit_success number(1,0) not null, granting number(1,0) not null, mask number(10,0) not null, sid number(19,0) not null, primary key (id), unique (acl_object_identity, ace_order));
create table acl_object_identity (id number(19,0) not null, object_id_class number(19,0) not null, entries_inheriting number(1,0) not null, object_id_identity number(19,0) not null, owner_sid number(19,0), parent_object number(19,0), primary key (id), unique (object_id_class, object_id_identity));
create table acl_sid (id number(19,0) not null, principal number(1,0) not null, sid varchar2(255 char) not null, primary key (id), unique (sid, principal));
create table application (id number(19,0) not null, version number(19,0) not null, deleted number(1,0) not null, description clob, identifier varchar2(255 char) not null unique, name varchar2(255 char) not null, class varchar2(255 char) not null, author_id number(19,0), project_id number(19,0), primary key (id));
create table application_parameter (id number(19,0) not null, version number(19,0) not null, application_id number(19,0) not null, default_value varchar2(255 char), description clob, editable number(1,0) not null, format varchar2(255 char) not null, hidden number(1,0) not null, label varchar2(255 char) not null, max_len number(19,0) not null, min_len number(19,0) not null, name varchar2(255 char) not null, optionnal number(1,0) not null, pos number(19,0) not null, possible_values varchar2(255 char), regex varchar2(255 char), type varchar2(255 char) not null, primary key (id));
create table application_version (id number(19,0) not null, version number(19,0) not null, application_id number(19,0) not null, date_created date not null, last_updated date not null, pre_script varchar2(255 char), pre_script_path varchar2(255 char), script varchar2(255 char) not null, script_path varchar2(255 char) not null, validation_script varchar2(255 char), validation_script_path varchar2(255 char), primary key (id));
create table authaccount (authaccountid number(19,0) not null, aclogin varchar2(255 char), authsystem_authsystemid number(19,0) not null, users_numuserid number(19,0) not null, primary key (authaccountid));
create table authsystem (numauthsystemid number(19,0) not null, authlogin varchar2(255 char), authpassword varchar2(255 char), authsystemid varchar2(255 char), authtype number(10,0), name varchar2(255 char), status number(10,0), uri varchar2(255 char), userpwdencryption number(10,0), vishnu_vishnuid number(19,0) not null, primary key (numauthsystemid));

create table clmachine (numclmachineid number(19,0) not null, name varchar2(255 char), sshkey varchar2(255 char), primary key (numclmachineid));
CREATE SEQUENCE s_clmachine;

CREATE OR REPLACE TRIGGER AINC_clmachine
BEFORE INSERT  ON clmachine
FOR EACH ROW
BEGIN
  IF (:NEW.numclmachineid IS NULL) THEN
    SELECT s_clmachine.NEXTVAL INTO :NEW.numclmachineid FROM DUAL;
  END IF;
END;
/
create table command (numcommandid number(19,0) not null, ctype number(10,0), description clob, endtime date, starttime date, status number(10,0), vishnuobjectid varchar2(255 char), vsession_numsessionid number(19,0) not null, primary key (numcommandid));
CREATE SEQUENCE s_command;

CREATE OR REPLACE TRIGGER AINC_command
BEFORE INSERT  ON command
FOR EACH ROW
BEGIN
  IF (:NEW.numcommandid IS NULL) THEN
    SELECT s_command.NEXTVAL INTO :NEW.numcommandid FROM DUAL;
  END IF;
END;
/
create table description (numdescriptionid number(19,0) not null, description clob, lang varchar2(255 char), machine_nummachineid number(19,0) not null, primary key (numdescriptionid));
CREATE SEQUENCE s_description;

CREATE OR REPLACE TRIGGER AINC_description
BEFORE INSERT  ON description
FOR EACH ROW
BEGIN
  IF (:NEW.numdescriptionid IS NULL) THEN
    SELECT s_description.NEXTVAL INTO :NEW.numdescriptionid FROM DUAL;
  END IF;
END;
/
create table filetransfer (numfiletransferid number(19,0) not null, clientmachineid varchar2(255 char), destinationfilepath varchar2(255 char), destinationmachineid varchar2(255 char), errormsg clob, filesize number(10,0), processid number(10,0), sourcefilepath varchar2(255 char), sourcemachineid varchar2(255 char), starttime date, status number(10,0), transferid varchar2(255 char), trcommand number(10,0), userid varchar2(255 char), vsession_numsessionid number(19,0) not null, primary key (numfiletransferid));
CREATE SEQUENCE s_filetransfer;

CREATE OR REPLACE TRIGGER AINC_filetransfer
BEFORE INSERT  ON filetransfer
FOR EACH ROW
BEGIN
  IF (:NEW.numfiletransferid IS NULL) THEN
    SELECT s_filetransfer.NEXTVAL INTO :NEW.numfiletransferid FROM DUAL;
  END IF;
END;
/
create table job (numjobid number(19,0) not null, batchjobid varchar2(255 char), batchtype number(10,0), enddate date, errorpath varchar2(255 char), groupname varchar2(255 char), job_owner_id number(19,0), jobdescription clob, jobid varchar2(255 char), jobname varchar2(255 char), jobpath varchar2(255 char), jobprio number(10,0), jobqueue varchar2(255 char), jobworkingdir varchar2(255 char), machine_id number(19,0), memlimit number(10,0), nbcpus number(10,0), nbnodes number(10,0), nbnodesandcpupernode varchar2(255 char), outputdir varchar2(255 char), outputpath varchar2(255 char), owner varchar2(255 char), scriptcontent clob, status number(10,0), submitdate date, submitmachineid varchar2(255 char), submitmachinename varchar2(255 char), vsession_numsessionid number(19,0) not null, wallclocklimit number(10,0), workId number(19,0), primary key (numjobid));
CREATE SEQUENCE s_job;

CREATE OR REPLACE TRIGGER AINC_job
BEFORE INSERT  ON job
FOR EACH ROW
BEGIN
  IF (:NEW.numjobid IS NULL) THEN
    SELECT s_job.NEXTVAL INTO :NEW.numjobid FROM DUAL;
  END IF;
END;
/
create table ldapauthsystem (ldapauthsystid number(19,0) not null, authsystem_authsystemid number(19,0) not null, ldapbase varchar2(255 char), primary key (ldapauthsystid));

create table machine (nummachineid number(19,0) not null, diskspace number(10,0), machineid varchar2(255 char), memory number(10,0), name varchar2(255 char), network number(10,0), site varchar2(255 char), sshpublickey clob, status number(10,0), vishnu_vishnuid number(19,0) not null, primary key (nummachineid));
CREATE SEQUENCE s_machine;

CREATE OR REPLACE TRIGGER AINC_machine
BEFORE INSERT  ON machine
FOR EACH ROW
BEGIN
  IF (:NEW.nummachineid IS NULL) THEN
    SELECT s_machine.NEXTVAL INTO :NEW.nummachineid FROM DUAL;
  END IF;
END;
/
create table notification (id number(19,0) not null, version number(19,0) not null, clazz varchar2(255 char) not null, content varchar2(255 char) not null, date_created date not null, link_to varchar2(255 char) not null, notifier_id number(19,0), object_id number(10,0) not null, project_id number(19,0) not null, type varchar2(255 char) not null, primary key (id));

create table optionu (numoptionid number(19,0) not null, defaultvalue number(10,0), description clob, optionid number(10,0), primary key (numoptionid));
CREATE SEQUENCE s_optionu;

CREATE OR REPLACE TRIGGER AINC_optionu
BEFORE INSERT  ON optionu
FOR EACH ROW
BEGIN
  IF (:NEW.numoptionid IS NULL) THEN
    SELECT s_optionu.NEXTVAL INTO :NEW.numoptionid FROM DUAL;
  END IF;
END;
/
create table optionvalue (numoptionvalueid number(19,0) not null, optionu_numoptionid number(19,0) not null, users_numuserid number(19,0) not null, value number(10,0), primary key (numoptionvalueid));
CREATE SEQUENCE s_optionvalue;

CREATE OR REPLACE TRIGGER AINC_optionvalue
BEFORE INSERT  ON optionvalue
FOR EACH ROW
BEGIN
  IF (:NEW.numoptionvalueid IS NULL) THEN
    SELECT s_optionvalue.NEXTVAL INTO :NEW.numoptionvalueid FROM DUAL;
  END IF;
END;
/
create table parameter_value (id number(19,0) not null, version number(19,0) not null, parent_id number(19,0) not null, type_id number(19,0) not null, value varchar2(255 char) not null, primary key (id));
create table permission (id number(19,0) not null, version number(19,0) not null, label varchar2(255 char) not null, member_required number(1,0) not null, module_id number(19,0) not null, name varchar2(255 char) not null unique, pos number(19,0) not null, project_required number(1,0) not null, primary key (id));
create table permission_module (id number(19,0) not null, version number(19,0) not null, name varchar2(255 char) not null unique, pos number(19,0) not null, primary key (id));

create table process (numprocess number(19,0) not null, dietname varchar2(255 char), launchscript clob, machineid varchar2(255 char), pstatus number(10,0), uptime date, vishnuname varchar2(255 char), primary key (numprocess));
CREATE SEQUENCE s_process;
CREATE OR REPLACE TRIGGER AINC_process
BEFORE INSERT ON process
FOR EACH ROW
BEGIN
  IF (:NEW.numprocess IS NULL) THEN
    SELECT s_process.NEXTVAL INTO :NEW.numprocess FROM DUAL;
  END IF;
END;
/
create table project (id number(19,0) not null, version number(19,0) not null, closed number(1,0) not null, date_created date not null, deleted number(1,0) not null, description clob not null, identifier varchar2(255 char) not null unique, is_public number(1,0) not null, last_updated date not null, name varchar2(30 char) not null unique, parent_id number(10,0) not null, primary key (id));
create table project_application (id number(19,0) not null, version number(19,0) not null, application_id number(19,0) not null, project_id number(19,0) not null, primary key (id));
create table project_machine (id number(19,0) not null, version number(19,0) not null, machine_id number(19,0) not null, max_allowed_time number(19,0) not null, project_id number(19,0) not null, spent_time number(19,0) not null, primary key (id));
create table project_member (id number(19,0) not null, version number(19,0) not null, date_created date not null, last_updated date not null, mail_notifications number(1,0) not null, member_id number(19,0) not null, project_id number(19,0) not null, primary key (id));
create table project_member_project_role (project_member_roles_id number(19,0), project_role_id number(19,0));
create table project_role (id number(19,0) not null, version number(19,0) not null, description clob, is_built_in number(1,0) not null, is_default number(1,0) not null, label varchar2(255 char) not null, member_specific number(1,0) not null, name varchar2(255 char) not null, pos number(19,0) not null, class varchar2(255 char) not null, project_id number(19,0), primary key (id));
create table project_role_permissions (project_role_id number(19,0), permissions_string varchar2(255 char));
create table role (id number(19,0) not null, version number(19,0) not null, authority varchar2(255 char) not null unique, description clob not null, primary key (id));

create table state (numstateid number(19,0) not null, cpuload number(10,0), diskspace number(10,0), machine_nummachineid number(19,0) not null, memory number(10,0), time date, primary key (numstateid));
CREATE SEQUENCE s_state;

CREATE OR REPLACE TRIGGER AINC_state
BEFORE INSERT  ON state
FOR EACH ROW
BEGIN
  IF (:NEW.numstateid IS NULL) THEN
    SELECT s_state.NEXTVAL INTO :NEW.numstateid FROM DUAL;
  END IF;
END;
/
create table threshold (thresholdid number(19,0) not null, machine_nummachineid number(19,0) not null, typet number(10,0), users_numuserid number(19,0) not null, value number(10,0), primary key (thresholdid));
CREATE SEQUENCE s_threshold;

CREATE OR REPLACE TRIGGER AINC_threshold
BEFORE INSERT  ON threshold
FOR EACH ROW
BEGIN
  IF (:NEW.thresholdid IS NULL) THEN
    SELECT s_threshold.NEXTVAL INTO :NEW.thresholdid FROM DUAL;
  END IF;
END;
/
create table user_role (role_id number(19,0) not null, user_id number(19,0) not null, primary key (role_id, user_id));

create table users (numuserid number(19,0) not null, account_expired number(1,0), account_locked number(1,0), confirm_code varchar2(255 char), date_created date, email varchar2(255 char), enabled number(1,0), firstname varchar2(255 char), last_updated date, lastname varchar2(255 char), pwd varchar2(255 char) not null, password_expired number(1,0), passwordstate number(10,0), privilege number(10,0), status number(10,0), userid varchar2(255 char) not null, vishnu_vishnuid number(19,0) not null, primary key (numuserid));
CREATE SEQUENCE s_users;

CREATE OR REPLACE TRIGGER AINC_users
BEFORE INSERT  ON users
FOR EACH ROW
BEGIN
  IF (:NEW.numuserid IS NULL) THEN
    SELECT s_users.NEXTVAL INTO :NEW.numuserid FROM DUAL;
  END IF;
END;
/
create table vishnu (vishnuid number(19,0) not null, formatidauth varchar2(255 char), formatidfiletransfer varchar2(255 char), formatidjob varchar2(255 char), formatidmachine varchar2(255 char), formatiduser varchar2(255 char), formatidwork varchar2(255 char), updatefreq number(10,0), primary key (vishnuid));
CREATE SEQUENCE s_vishnu;

CREATE OR REPLACE TRIGGER AINC_vishnu
BEFORE INSERT  ON vishnu
FOR EACH ROW
BEGIN
  IF (:NEW.vishnuid IS NULL) THEN
    SELECT s_vishnu.NEXTVAL INTO :NEW.vishnuid FROM DUAL;
  END IF;
END;
/
create table vsession (numsessionid number(19,0) not null, authid varchar2(255 char), clmachine_numclmachineid number(19,0) not null, closepolicy number(10,0), closure date, creation date, lastconnect date, sessionkey varchar2(255 char), state number(10,0), timeout number(10,0), users_numuserid number(19,0) not null, vsessionid varchar2(255 char), primary key (numsessionid));
CREATE SEQUENCE s_vsession;

CREATE OR REPLACE TRIGGER AINC_vsession
BEFORE INSERT  ON vsession
FOR EACH ROW
BEGIN
  IF (:NEW.numsessionid IS NULL) THEN
    SELECT s_vsession.NEXTVAL INTO :NEW.numsessionid FROM DUAL;
  END IF;
END;
/
create table work (id number(19,0) not null, application_id number(19,0), date_created date not null, date_ended date, date_started date, description clob, done_ratio number(19,0) not null, due_date date, estimated_hours double precision not null, identifier varchar2(255 char) not null, last_updated date not null, machine_id number(19,0), nbcpus number(10,0) not null, owner_id number(19,0) not null, priority number(10,0) not null, project_id number(19,0), start_date date, status number(10,0) not null, subject varchar2(255 char) not null, submit_date date, primary key (id));
CREATE SEQUENCE s_work;

CREATE OR REPLACE TRIGGER AINC_work
BEFORE INSERT  ON work
FOR EACH ROW
BEGIN
  IF (:NEW.id IS NULL) THEN
    SELECT s_work.NEXTVAL INTO :NEW.id FROM DUAL;
  END IF;
END;
/
alter table GlobProj_permissions add constraint FK6F40D05A8D89FC97 foreign key (global_project_role_id) references GlobProj;
alter table account add constraint FKB9D38A2D1CFEDEFC foreign key (machine_nummachineid) references machine ON DELETE CASCADE;
alter table account add constraint FKB9D38A2DA63719F2 foreign key (users_numuserid) references users ON DELETE CASCADE;
alter table acl_entry add constraint FK5302D47D8FDB88D5 foreign key (sid) references acl_sid;
alter table acl_entry add constraint FK5302D47DB0D9DC4D foreign key (acl_object_identity) references acl_object_identity;
alter table acl_object_identity add constraint FK2A2BB009A50290B8 foreign key (parent_object) references acl_object_identity;
alter table acl_object_identity add constraint FK2A2BB00970422CC5 foreign key (object_id_class) references acl_class;
alter table acl_object_identity add constraint FK2A2BB00990EC1949 foreign key (owner_sid) references acl_sid;
alter table application add constraint FK5CA40550BD4995A3 foreign key (project_id) references project;
alter table application add constraint FK5CA40550E1F3BA8C foreign key (author_id) references users;
alter table application_parameter add constraint FKFA594F7A3462EA58 foreign key (application_id) references application_version;
alter table application_version add constraint FKC5B678E99FCAFF4 foreign key (application_id) references application;
alter table authaccount add constraint FK2C887F85A63719F2 foreign key (users_numuserid) references users ON DELETE CASCADE;
alter table authaccount add constraint FK2C887F85FC5A9563 foreign key (authsystem_authsystemid) references authsystem ON DELETE CASCADE;
alter table authsystem add constraint FKADC771D7C2584CA8 foreign key (vishnu_vishnuid) references vishnu;
alter table command add constraint FK38A5DF4BF58538BC foreign key (vsession_numsessionid) references vsession ON DELETE CASCADE;
alter table description add constraint FK993583FC1CFEDEFC foreign key (machine_nummachineid) references machine ON DELETE CASCADE;
alter table filetransfer add constraint FKFCE97167F58538BC foreign key (vsession_numsessionid) references vsession ON DELETE CASCADE;
alter table job add constraint FK19BBDF381DC90 foreign key (workId) references work;
alter table job add constraint FK19BBDF58538BC foreign key (vsession_numsessionid) references vsession ON DELETE CASCADE;
alter table job add constraint FK19BBD9207FB3B foreign key (machine_id) references machine;
alter table job add constraint FK19BBD355BF2A6 foreign key (job_owner_id) references users;
alter table ldapauthsystem add constraint FK30E4E8BEFC5A9563 foreign key (authsystem_authsystemid) references authsystem ON DELETE CASCADE;
alter table machine add constraint FK31314447C2584CA8 foreign key (vishnu_vishnuid) references vishnu;
alter table notification add constraint FK237A88EB7276891 foreign key (notifier_id) references users;
alter table notification add constraint FK237A88EBBD4995A3 foreign key (project_id) references project;
alter table optionvalue add constraint FKEBDE0A1CBE23B1A5 foreign key (optionu_numoptionid) references optionu;
alter table optionvalue add constraint FKEBDE0A1CA63719F2 foreign key (users_numuserid) references users ON DELETE CASCADE;
alter table parameter_value add constraint FK2E32855B3CCF497F foreign key (type_id) references application_parameter;
alter table parameter_value add constraint FK2E32855B9D863974 foreign key (parent_id) references work;
alter table permission add constraint FKE125C5CF6E594880 foreign key (module_id) references permission_module;
alter table project_application add constraint FKFAD3D12A9FCAFF4 foreign key (application_id) references application;
alter table project_application add constraint FKFAD3D12ABD4995A3 foreign key (project_id) references project;
alter table project_machine add constraint FKA2850D21BD4995A3 foreign key (project_id) references project;
alter table project_machine add constraint FKA2850D219207FB3B foreign key (machine_id) references machine;
alter table project_member add constraint FK2EC53E80DA00831D foreign key (member_id) references users;
alter table project_member add constraint FK2EC53E80BD4995A3 foreign key (project_id) references project;
alter table project_member_project_role add constraint FK19B3B13BC94BA396 foreign key (project_role_id) references project_role;
alter table project_member_project_role add constraint FK19B3B13B9EDD7798 foreign key (project_member_roles_id) references project_member;
alter table project_role add constraint FK37FFF5DCBD4995A3 foreign key (project_id) references project;
alter table project_role_permissions add constraint FKADD15EA1C94BA396 foreign key (project_role_id) references project_role;
alter table state add constraint FK68AC4911CFEDEFC foreign key (machine_nummachineid) references machine ON DELETE CASCADE;
alter table threshold add constraint FKA3E1E46B1CFEDEFC foreign key (machine_nummachineid) references machine ON DELETE CASCADE;
alter table threshold add constraint FKA3E1E46BA63719F2 foreign key (users_numuserid) references users;
alter table user_role add constraint FK143BF46ADC10046C foreign key (role_id) references role ON DELETE CASCADE;
alter table user_role add constraint FK143BF46A813AC84C foreign key (user_id) references users ON DELETE CASCADE;
alter table users add constraint FK6A68E08C2584CA8 foreign key (vishnu_vishnuid) references vishnu;
alter table vsession add constraint FK581B3160C401BD40 foreign key (clmachine_numclmachineid) references clmachine;
alter table vsession add constraint FK581B3160A63719F2 foreign key (users_numuserid) references users ON DELETE CASCADE;
alter table work add constraint FK37C7113462EA58 foreign key (application_id) references application_version;
alter table work add constraint FK37C711BD4995A3 foreign key (project_id) references project ON DELETE CASCADE;
alter table work add constraint FK37C7119207FB3B foreign key (machine_id) references machine ON DELETE CASCADE;
alter table work add constraint FK37C711ED217864 foreign key (owner_id) references users ON DELETE CASCADE;
create sequence hibernate_sequence;
