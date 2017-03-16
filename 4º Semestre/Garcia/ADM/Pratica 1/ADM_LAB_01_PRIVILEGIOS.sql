--Roteiro Laboratório para Admnistração de Usuários:

--Instruções de execução:
-- - Cada item do experimento deve ser executado e o seu resultado documentado no relatório.

--Objetivo do laboratório:
-- - Conhecer e estudar as visões do dicionários de dados e os comandos do Oracle que gerenciam os privilégios dos usuários. Algumas
--   visões do dicionário serão utilizadas para tal.
-- - Para este primeiro laboratório, documente e explique todos os comandos.

connect com o usuario SYSTEM

SELECT * FROM v$version;

CREATE TABLESPACE TBS_LAB01 DATAFILE 'C:\oraclexe\app\oracle\oradata\XE\LAB01.dbf' SIZE 5M autoextend on;

SELECT initial_extent,next_extent, extent_management, allocation_type,segment_space_management FROM dba_tablespaces;

ALTER TABLESPACE TBS_LAB01 ADD DATAFILE 'C:\oraclexe\app\oracle\oradata\XE\LAB02.dbf' SIZE 5M autoextend on;

SELECT username FROM dba_users;

CREATE USER USR_LAB01 IDENTIFIED BY SENHA default tablespace lab01;

ALTER USER USR_LAB01 IDENTIFIED BY new_password;

SELECT default_tablespace, temporary_tablespace FROM dba_users WHERE username='USR_LAB01';

SHOW USER

GRANT CONNECT, RESOURCE to USR_LAB01;

CREATE TABLE xyz (name VARCHAR2(30));

CREATE TABLE USR_LAB01.xyz2 (name VARCHAR2(30));

GRANT CREATE TABLE TO USR_LAB01;

CREATE USER USR_LAB02 IDENTIFIED BY SENHA TEMPORARY TABLESPACE TEMP DEFAULT TABLESPACE USR_LAB01;

GRANT INSERT, DELETE, SELECT ON USR_LAB01.XYZ2 TO USR_LAB02 WITH GRANT OPTION;

grant connect to USR_lab02;

select * from dba_tab_privs where grantee = 'USR_LAB02';
Observar no resultado desse select que o grantor é diferente do owner

DROP USER USR_LAB02;

CREATE ROLE new_dba;

GRANT CONNECT TO new_dba;
GRANT SELECT ANY TABLE TO new_dba;
GRANT UPDATE ANY TABLE TO new_dba;
GRANT select_catalog_role TO new_dba;
GRANT exp_full_database TO new_dba;
GRANT imp_full_database TO new_dba;

grant new_dba to USR_LAB01;

select * from dba_sys_privs;

conectar com o usuario USR_LAB02
Inserir registros na tabela USR_LAB01.XYZ2;
Selecionar os registros inseridos;
Excluir alguns registros inseridos;
