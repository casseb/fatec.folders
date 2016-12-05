----------------Comandos de inicialização-------------------------------
connect USER_PRATICA05/aluno
clear scr
set serveroutput on
/*
----------------Preparando Banco-----------------------------------------

CREATE USER &Usuario IDENTIFIED BY &senha;

GRANT ALL PRIVILEGES TO &usuario;

alter session set nls_date_format = 'DD/MM/YYYY HH24:MI:SS';

----------------------Criar Table space--------------------------------

CREATE TABLESPACE  TS_DB_2015
DATAFILE  'C:\BD\ts_db_2015.dbf' SIZE 1M
AUTOEXTEND ON;

----------------------Criar Usuario--------------------------------

CREATE USER USER_VENDA
IDENTIFIED BY aluno
DEFAULT TABLESPACE ts_db_2015
TEMPORARY TABLESPACE TEMP
QUOTA UNLIMITED ON ts_db_2015;

----------------------Privilegios--------------------------------

GRANT DBA TO USER_VENDA WITH ADMIN OPTION;

-----------------------Consultando todas as tabelas-----------------------

select
rownum, table_name from all_tables
where owner = 'VENDA';

--desc departamento


-----------------------Consultando todas as constraints--------------------

select
rownum, constraint_name from all_cons_columns
where owner = '&Banco';

-----------------------Consultando todas as Sequences--------------------

select
rownum, sequence_name from all_sequences
where sequence_owner = 'JOGO';

-----------------------Apagando Sequence--------------------------------

drop sequence &SequenceName;

---------------------Consultando todo o conteudo da tabela--------------------

select
* from &Tabela;

----------------------Tabela Principal de Teste------------------------------

drop table teste;

create table teste (
  codigo number(5),
  nome varchar2(50),
  descricao varchar2(150),
  constraint teste_pk primary key (codigo)
);

insert into teste
  (codigo, nome, descricao) values
  (1,'teste1', 'Registro de teste 1');

insert into teste
  (codigo, nome, descricao) values
  (2,'teste2', 'Registro de teste 2');

insert into teste
  (codigo, nome, descricao) values
  (3,'teste3', 'Registro de teste 3');

----------------------Pl SQL------------------------------------------------

SET SERVEROUTPUT ON
ACCEPT p_nome PROMPT 'Digite o nome do funcionário...'
ACCEPT p_sal_mes PROMPT 'Digite o valor do salário...'
Declare
v_nome varchar2(30) := '&p_nome';
v_sal number(9,2) := &p_sal_mes;
v_sal_anual number(9,2);
Begin
v_sal_anual := v_sal * 12;
DBMS_output.put_line('O salário anual de ' || v_nome || ' é ' ||
v_sal_anual);
END;
/

VARIABLE g_sal_anual NUMBER
ACCEPT p_sal_mes PROMPT 'Digite o valor do salário...'
Declare
v_sal number(9,2) := &p_sal_mes;
Begin
:g_sal_anual := v_sal * 12;
END;
/
PRINT g_sal_anual

VARIABLE g_sal_anual NUMBER
Declare
v_sal number(9,2) :=100;
Begin
:g_sal_anual := v_sal * 12;
END;
/
PRINT g_sal_anual

Set Serveroutput On
Begin
  For i In REVERSE 1..10 Loop
    DBMS_output.put_line('i: ' || i);
  END LOOP;
END;
----------------------Sequence------------------------------------------------

create sequence dep_id_seq
increment by 10
start with 120
maxvalue 9999;

select sequence_name, min_value, max_value, increment_by, last_number
from user_sequences
where sequence_name = 'DEP_ID_SEQ';

----------------------View------------------------------------------------

create or replace view Funcionario_view as (
  select f.fun_cod,f.fun_nome,f.fun_logradouro,c.cid_nome,e.est_estado,car.car_descricao, d.dep_descricao, f.fun_obs
  from funcionario f join cargo car on f.car_cod = car.car_cod join
  Departamento d on f.dep_cod = d.dep_cod join
  Cidade c on c.cid_cod = f.cid_cod and c.est_cod = f.est_cod join
  Estado e on c.est_cod = e.est_cod
) with read only;

desc Funcionario_view;

----------------------Comandos Variados------------------------------------------------

select distinct g.grav_nome from
gravadora g join cd c on g.grav_codigo = c.grav_codigo
where cd_preco_venda < 80;

select * from cd
where cd_preco_venda in (
  select max(c.cd_preco_venda) from
  gravadora g join cd c on g.grav_codigo = c.grav_codigo
  group by g.grav_codigo);

select * from cd
where cd_preco_venda < any (
  select cd_preco_venda from
  cd where grav_codigo = 10
);

select * from cd
where cd_preco_venda < all(
  select avg(c.cd_preco_venda) from
  gravadora g join cd c on g.grav_codigo = c.grav_codigo
  group by g.grav_codigo);

select initcap(cd_nome) from
cd where
cd_preco_venda > 10 or
grav_codigo = 3
order by cd_nome desc;

select c.cd_nome, c.cd_data_lancamento, g.grav_nome from
gravadora g join cd c on g.grav_codigo = c.grav_codigo
where c.cd_data_lancamento between('28/12/2013') and ('28/08/2018');

select c.cd_nome, g.grav_nome from
gravadora g right join cd c on g.grav_codigo = c.grav_codigo;

select c.cd_codigo, count(*) from
cd c join faixa f on c.cd_codigo = f.cd_codigo
group by c.cd_codigo;

select c.cd_codigo, cat.cat_codigo from
cd c join cd_categoria cat on c.cd_preco_venda between cat.menor_preco and cat.maior_preco;

select c1.cd_nome, c2.cd_nome from
cd c1 join cd c2 on c1.cd_indicado = c2.cd_codigo;

select * from CD_CATEGORIA;

select distinct c.cd_codigo, c.cd_nome, c.cd_preco_venda,g.grav_nome, sum (m.mus_duracao) from
cd c join faixa f on c.cd_codigo = f.cd_codigo join musica m on f.mus_codigo = m.mus_codigo
join gravadora g on c.grav_codigo = g.grav_codigo
where c.cd_codigo = 11
group by c.cd_codigo, c.cd_nome, c.cd_preco_venda,g.grav_nome;

select * from (
  select g.grav_codigo, count(*) quantidade from
  cd c join gravadora g on c.grav_codigo = g.grav_codigo
  group by g.grav_codigo
)where quantidade > 2;

select mus_nome from musica where
mus_duracao in
(select max(mus_duracao) from musica);

select c.cd_nome, f.faixa_numero, m.mus_nome
from cd c join faixa f on c.cd_codigo = f.cd_codigo join
musica m on m.mus_codigo = f.mus_codigo
where c.cd_codigo in (102,103);

select aut_codigo codigo, aut_nome autor from autor
where aut_codigo < 10
union
select mus_codigo codigo, mus_nome nome_musica from musica
where mus_codigo < 15;

select * from cd
where cd_preco_venda < all(
  select avg(cd_preco_venda) from
  cd group by grav_codigo
);

select cd_nome from CD
where cd_preco_venda < ANY (
  select cd_preco_venda from cd
  where grav_codigo = 2
);

select cd_codigo,cd_nome from
cd
where cd_preco_venda in (
  select min(cd_preco_venda) from
  cd
  group by (grav_codigo)
);

select nome_curso
from curso_velho
where nome_curso like '%Básico%'
union
select nome_curso
from curso
where nome_curso like '%Básico%';

select nome_curso
from curso_velho
where nome_curso like '%Básico%'
union all
select nome_curso
from curso
where nome_curso like '%Básico%';

select nome_curso
from curso_velho
where nome_curso like '%Básico%'
intersect
select nome_curso
from curso
where nome_curso like '%Básico%';

select nome_curso
from curso_velho
minus
select nome_curso
from curso;

---------------------Limpando uma tabela completamente--------------------------

delete from
&Tabela;

-------------------------------Manipulando Datas Oracle-------------------------

select sysdate from dual;
select add_months ('27/08/2013',02) from dual;
select months_between('28/12/2013','28/08/2013') from dual;
select next_day('18/08/2014','SEXTA') from dual;
select last_day('14/08/2016') from dual;
select extract (year from sysdate) ano from dual;


-------------------------------Matemática---------------------------------

select power(3,2) from dual;
select sqrt(9) from dual;
select ceil(7.4) from dual;


-------------------------------Conversão de dados-----------------------------

select to_char(sysdate,' CC DD/MM/YY HH24:MI') from dual;
select to_char(sysdate,' CC D/MM/YY HH24:MI') from dual;
select to_char(sysdate,' CC DDD/MM/YY HH24:MI') from dual;
select to_number('12345') from dual;
select to_date('10111978','DD/MM/YY') from dual;

-----------------------Pratica01 - LPBD-------------------------------------

select sum(func_sal)
from funcionario
where dep_id = 2;

select avg(func_sal), sum(func_sal)
from funcionario;

update funcionario set gerente_cod = 5 where func_cod between 1 and 4;

select f.func_cod, f.func_nome, f.func_sal, fs.fa_cod from
funcionario f join faixa_salarial fs on f.func_sal between fs.fa_menor and fs.fa_maior;

select f.func_cod, f.func_nome, d.dep_id, d.dep_descricao
from funcionario f full join departamento d
on f.dep_id = d.dep_id;

select f.func_cod, f.func_nome, d.dep_id, d.dep_descricao
from funcionario f right join departamento d
on f.dep_id = d.dep_id;

insert into
cta_conta
(CTA_NOME,CTA_SENHA,CTA_DATA_EXPIRACAO) values
('Batman','BecauseIambatman',TO_DATE('2016-05-17', 'YYYY-MM-DD'));

---------------------------     Lambança do CURRVAL      ------------------------------

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Batmovel','Carro do batman',99999.99,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('19/10/2016','DD/MM/YYYY'));

--------------------------------- Comandos DML --------------------------------------

------------------   Conferindo constrains que possuem relação com o nome da cta_conta

select
rownum,constraint_name from all_cons_columns
where owner = 'JOGO' and constraint_name like '%CTA%';

------------------ Deletando as constrains relacionadas

alter table cpa_compra
drop constraint CPA_CTA_FK;

-----------------   Editando o nome da conta nas tabelas relacionadas

update
cta_conta
set cta_nome = 'BATMANFALLS'
where cta_nome = 'Batman';

Alter TABLE
CTA_CONTA
ADD CONSTRAINT CTA_CONTA_PK PRIMARY KEY (CTA_NOME);

DELETE FROM ser_servico
WHERE ITE_CODIGO = 4;

--------------------------------- Selects zicas --------------------------------------


SELECT
ITE_ITEM.ITE_NOME, ITE_ITEM.ITE_DESCRICAO,ITE_ITEM.ITE_VALOR FROM
ITE_ITEM JOIN VEI_VEICULO ON ITE_ITEM.ITE_CODIGO = VEI_VEICULO.ITE_CODIGO;

SELECT
PTA_PISTA.PTA_NOME, MIN(COR_CORRIDA.COR_TEMPO)
FROM
PTA_PISTA JOIN COR_CORRIDA ON PTA_PISTA.PTA_NOME = COR_CORRIDA.PTA_NOME
GROUP BY PTA_PISTA.PTA_NOME;



SELECT * FROM
	(
	SELECT
  CPA_COMPRA.CTA_NOME,COUNT(CPA_COMPRA.CTA_NOME) QTD_SERVICOS FROM
  CPA_COMPRA JOIN CIT_ITEM_COMPRA ON CPA_COMPRA.CPA_DATA_HORA = CIT_ITEM_COMPRA.CPA_DATA_HORA
	JOIN SER_SERVICO ON CIT_ITEM_COMPRA.ITE_CODIGO = SER_SERVICO.ITE_CODIGO
  GROUP BY CPA_COMPRA.CTA_NOME
	ORDER BY QTD_SERVICOS
  )
WHERE ROWNUM = 1;


SELECT CTA_CONTA.CTA_NOME, CIT_ITEM_COMPRA.CPA_DATA_HORA FROM
CIT_ITEM_COMPRA JOIN VEI_VEICULO ON CIT_ITEM_COMPRA.ITE_CODIGO = VEI_VEICULO.ITE_CODIGO JOIN
CTA_CONTA ON CTA_CONTA.CTA_NOME = CIT_ITEM_COMPRA.CTA_NOME;


select
cta_conta.cta_nome
from
cta_conta,cpa_compra
where
cta_conta.cta_nome = cpa_compra.cta_nome and
cpa_compra.cpa_data_hora > TO_DATE('01/02/2016','DD/MM/YYYY');

---------------------Prática 4----------------------------------------------


DECLARE
  V_FUN_COD NUMBER(4);
  V_FUN_NOME VARCHAR2(30);

Begin
  SELECT FUN_COD, fun_nome
  INTO V_FUN_COD, V_FUN_NOME
  FROM Funcionario
  WHERE FUN_COD = 1;
  DBMS_output.put_line(V_FUN_NOME);
END;

DECLARE
  V_FUN_COD NUMBER(4);
  V_FUN_NOME VARCHAR2(30);

Begin
  SELECT FUN_COD, fun_nome
  INTO V_FUN_COD, V_FUN_NOME
  FROM Funcionario
  WHERE FUN_COD = 1;
  DBMS_output.put_line(V_FUN_NOME);
END;
  /

  DECLARE

  v_est_cod estado.est_cod%type := 44
  v_est_estado estado.est_estado%type := 'XX';

  BEGIN

  insert into
  estado
  (est_cod,est_estado) values
  (v_est_cod, v_est_estado);

  END;

  /

  DECLARE

  v_est_estado estado.est_estado%type := 'EX';

  BEGIN

  update
  estado
  set est_estado = v_est_estado
  where est_estado = 'XX';

  END;

  /

  DECLARE

  v_est_estado estado.est_estado%type := 'EX';

  BEGIN

  delete from
  estado
  where est_estado = v_est_estado;

  END;

  /

  DECLARE

  v_est_cod estado.est_cod%type := 44;
  v_est_estado estado.est_estado%type := 'XX';

  BEGIN

  insert into
  estado
  (est_cod,est_estado) values
  (v_est_cod, v_est_estado);
  commit;

  delete from
  estado
  where est_estado = v_est_estado;
  rollback;
  END;

  select i.exe_cod,e.exe_descricao
  from  item_emprestimo i join exemplar e on
  i.exe_cod=e.exe_cod
  where i.emp_cod = 1;

  select l.liv_titulo, count(*) Quantidade from
  livro l join exemplar e on l.liv_cod = e.liv_cod
  group by l.liv_titulo;

  select p.pes_nome, prof.titulacao, t.tel_numero from
  pessoa p join Professor prof on p.pes_cod = prof.pes_cod
  left join Telefone t on t.pes_cod = p.pes_cod;


  select p.pes_nome, prof.titulacao, t.tel_numero from
  Pessoa p, Professor prof, Telefone t
  where
  p.pes_cod = prof.pes_cod and
  p.pes_cod(+) = t.pes_cod;

  select pes_nome from (
  select p.pes_nome, count(*) quantidade from
  Pessoa p join emprestimo e on p.pes_cod = e.pes_cod
  group by p.pes_nome
  )
  where rownum = 1
  order by quantidade;

  select distinct p.pes_nome from
  Pessoa p join Emprestimo e on p.pes_cod = e.pes_cod
  join Devolucao d on e.emp_cod = d.emp_cod
  where d.data_dev > e.emp_data_prevdev;

  create or replace view view_emprestimo as (
    select i.exe_cod from
    emprestimo e join item_emprestimo i on e.emp_cod = i.emp_cod
    where e.pes_cod = 1
  );

  select max(edi_cod)+1 from editora;

  create sequence edi_cod start with 3;

  SET SERVEROUTPUT ON
  ACCEPT p_liv_codigo PROMPT 'Digite o código do livro: '
  Declare
  v_liv_codigo livro.liv_cod%type := &p_liv_codigo;
  v_quant number;
  Begin
    select count(*)
      into v_quant
      from exemplar
      where liv_cod = v_liv_codigo;
      DBMS_output.put_line('Quantidade de exemplares: ' || v_quant);
  End;

  Declare

  V_ename emp.ename%type;
  V_mgr emp.mgr%type;

  Begin
  Select ename into v_ename from emp where ename='JAMES';
  IF v_ename = 'JAMES' THEN
    v_mgr := 22;
  END IF;
  Dbms_output.put_line('valor de v_mgr ' || v_mgr );
  End;

  Set serveroutput on
  ACCEPT p_n1 Prompt 'Entre com o primeiro numero: '
  ACCEPT p_n2 Prompt 'Entre com o segundo numero: '

  Declare

  v_n1 number(5);
  v_n2 number(5);

  Begin

  v_n1 := &p_n1;
  v_n2 := &p_n2;
  v_n1 := v_n1 + v_n2;
  dbms_output.put_line('Soma = ' || v_n1);

  End;


  Set serveroutput on
  ACCEPT p_n Prompt 'Entre com o numero: '

  Declare

  v_n number(5);

  Begin

  v_n := &p_n;

  dbms_output.put_line('Numero ' || v_n);

  End;


  Set serveroutput on
  ACCEPT p_n Prompt 'Entre com o numero: '

  Declare

  v_n number(5);

  Begin

  v_n := &p_n;

  dbms_output.put_line('Resultado ' || power(v_n,2));

  End;

  Set serveroutput on
  ACCEPT p_ano Prompt 'Entre com o ano: '

  Declare

  v_ano Date;

  Begin

  v_ano := to_date('&p_ano','YYYY');

  dbms_output.put_line('Resultado ' || floor(months_between(sysdate,v_ano)/12));

  End;

  Set serveroutput on
  ACCEPT p_n Prompt 'Entre com o numero: '

  Declare

  v_n number(5);

  Begin

  v_n := &p_n;

  if (mod(v_n,2) = 0) THEN
    dbms_output.put_line('o numero ' || v_n || ' e par');
  else
    dbms_output.put_line('o numero ' || v_n || ' e impar');
  end if;

  End;

  Set serveroutput on
  ACCEPT p_n1 Prompt 'Entre com o numero: '
  ACCEPT p_n2 Prompt 'Entre com o numero: '
  ACCEPT p_n3 Prompt 'Entre com o numero: '

  Declare

  v_n1 number(5);
  v_n2 number(5);
  v_n3 number(5);
  v_aux number(5);

  Begin

  v_n1 := &p_n1;
  v_n2 := &p_n2;
  v_n3 := &p_n3;

  if(v_n2 < v_n1) THEN
    v_aux := v_n1;
    v_n1 := v_n2;
    v_n2 := v_aux;
  end if;

  if(v_n3 < v_n2) THEN
    v_aux := v_n2;
    v_n2 := v_n3;
    v_n3 := v_aux;
  end if;

  if(v_n2 < v_n1) THEN
    v_aux := v_n1;
    v_n1 := v_n2;
    v_n2 := v_aux;
  end if;

  dbms_output.put_line(v_n1 || ' ' || v_n2 || ' ' || v_n3);

  End;


  Set serveroutput on
  ACCEPT p_n Prompt 'Entre com o numero: '

  Declare
  v_n number(5);
  v_resultado number(5);

  Begin
    for i in 0..10 Loop
      v_resultado := i*v_n;
      dbms_output.put_line(v_n || ' X ' || i || ' = ' || v_resultado);
    end loop;
  End;

  Set serveroutput on
  ACCEPT p_n1 Prompt 'Entre com o numero1 : '
  ACCEPT p_n2 Prompt 'Entre com o numero2 : '
  ACCEPT p_escolha Prompt 'Entre com a opção desejada 1 – Divisão;  2 – resto da divisão; 3 – adição;  4 – multiplicação : '

  Declare
  v_n1 number(5);
  v_n2 number(5);
  v_escolha number(5);

  Begin
    v_n1 := &p_n1;
    v_n2 := &p_n2;
    v_escolha := &p_escolha;

    case
      when v_escolha = 1 THEN
        dbms_output.put_line('Resposta = ' || v_n1/v_n2);
      when v_escolha = 2 THEN
        dbms_output.put_line('Resposta = ' || mod(v_n1,v_n2));
        when v_escolha = 3 THEN
          dbms_output.put_line('Resposta = ' || v_n1+v_n2);
        when v_escolha = 4 THEN
          dbms_output.put_line('Resposta = ' || v_n1*v_n2);
      else
        dbms_output.put_line('Opcao invalida');
      end case;
  End;


drop table teste;

create table teste (
  codigo number(5),
  nome varchar2(50),
  descricao varchar2(150),
  constraint teste_pk primary key (codigo)
);

insert into teste
  (codigo, nome, descricao) values
  (1,'teste1', 'Registro de teste 1');

insert into teste
  (codigo, nome, descricao) values
  (2,'teste2', 'Registro de teste 2');

insert into teste
  (codigo, nome, descricao) values
  (3,'teste3', 'Registro de teste 3');


  ------------Exercicio 1
  VARIABLE resultado VARCHAR2(30)
  DECLARE v_codigo NUMBER:=1;
  BEGIN
  Select codigo into v_codigo from teste WHERE codigo=v_codigo;
  :resultado:=(SQL%ROWCOUNT ||' Linhas encontradas');
  END;
  /
  print resultado;

  ------------Exercício 2

  VARIABLE resultado VARCHAR2(30)
  DECLARE
  v_codigo teste.codigo%type := 4;
  v_nome teste.nome%type := 'teste4';
  v_descricao teste.descricao%type := 'Registro de teste 4';

  BEGIN
  insert into teste (codigo, nome, descricao) values
    (v_codigo,v_nome, v_descricao);
  :resultado:=(SQL%ROWCOUNT ||' Linhas inseridas');
  END;
  /
  print resultado;

  -------------Exercício 3

  VARIABLE resultado VARCHAR2(30)
  DECLARE v_codigo NUMBER:=1;
  BEGIN
  update teste set descricao = 'Alterado' WHERE codigo=v_codigo;
  :resultado:=(SQL%ROWCOUNT ||' Linhas alteradas');
  END;
  /
  print resultado;

  -------------Exercício 4

  VARIABLE resultado VARCHAR2(30)
  DECLARE v_codigo NUMBER:=1;
  BEGIN
  Delete from teste WHERE codigo=v_codigo;
  if SQL%FOUND then
    :resultado:=(SQL%ROWCOUNT ||'LINHAS APAGADAS');
  else
    :resultado:=('Nenhuma linha foi apagada');
    end if;
  END;
  /
  print resultado;

  -------------Exercício 5

  VARIABLE resultado VARCHAR2(30)
  DECLARE v_codigo NUMBER:=1;
  BEGIN
  Select codigo into v_codigo from teste WHERE codigo=v_codigo;
  if SQL%NOTFOUND then
  :resultado:=('Nenhuma linha foi encontrada');
  else
  :resultado:=(SQL%ROWCOUNT ||'LINHAS ENCONTRADAS');
  end if;
  END;
  /
  print resultado;

  create table emp_tab
  (empid number(10) primary key,
  emp_nome varchar2(30),
  sal number(10,2),
  depid number(10));

-------------------------Trigger-------------------------------------

CREATE OR REPLACE TRIGGER Imp_Altera_Salarial
BEFORE DELETE OR INSERT OR UPDATE
ON Emp_tab
FOR EACH ROW WHEN ( new.EmpID > 0)
DECLARE sal_diff number ;
BEGIN
sal_diff :=  :new.sal - :old.sal;
dbms_output.put_line ( 'Old salary: ' || :old.sal ) ;
dbms_output.put_line ( ' Difference ' || sal_diff ) ;
dbms_output.put_line ( 'New salary: ' || :new.sal ) ;
END;



CREATE OR REPLACE TRIGGER aumento_salarial
AFTER UPDATE ON Emp_tab
BEGIN
INSERT INTO Emp_log (Data, Msg)
VALUES (SYSDATE, 'Mudança em Emp_tab');
END;

insert into emp_tab (empid,emp_nome,sal,depid) values (4,'Alfafa',600.00,3);

desc emp_tab

update emp_tab set emp_nome = 'Alfafa Mor', sal = 615.00;

select * from emp_tab;

create table emp_log
(data date, msg varchar2(50));



-----------------------------Package---------------------------------------

create or replace Package exemplo_package
  is
  procedure concatena_string (p_string1 in varchar2, p_string2 in varchar2, p_string_result out varchar2);

end exemplo_package;



create or replace Package body exemplo_package
  is
  procedure concatena_string (p_string1 in varchar2, p_string2 in varchar2, p_string_result out varchar2)
  is
  BEGIN
  p_string_result := concat(p_string1,p_string2);
  end concatena_string;
end exemplo_package;



create table Empregado (
  cpf varchar2(50),
  nome varchar2(50),
  depto number(5),
  salario number(38,2)
 );

create table Departamento(
  cod number(5),
  nome varchar2(50),
  total_sal number(38,2)
);


create or replace Trigger total_salario1
  after insert or delete or update on Empregado
  for each row
  BEGIN

    if inserting then

      update departamento set
      total_sal = total_sal+:new.salario
      where cod = :new.depto;

    end if;

    if updating then

          if (:old.salario <> :new.salario) then
           update departamento set
             total_sal = total_sal+(:new.salario - :old.salario)
             where cod = :new.depto;
          end if;

           if(:old.depto <> :new.depto) then
           update departamento set
             total_sal = total_sal-:old.salario
             where cod = :old.depto;
             update departamento set
               total_sal = total_sal+:new.salario
               where cod = :new.depto;
           end if;

    end if;

    if deleting then
      update departamento set
      total_sal = total_sal-:old.salario
      where cod = :old.depto;
    end if;
  end;

/*


CREATE OR REPLACE PACKAGE JOB_PACK
IS

  PROCEDURE add_job (p_jobid    IN jobs.empno%TYPE, p_jobtitle IN jobs.job%TYPE);
  PROCEDURE upd_job (p_jobid    IN jobs.empno%TYPE, p_jobtitle IN jobs.job%TYPE);
  PROCEDURE del_job (p_jobid IN jobs.empno%TYPE);
  FUNCTION q_job (p_jobid IN jobs.empno%TYPE) RETURN VARCHAR2;

END JOB_PACK;


create or replace PACKAGE BODY JOB_PACK
IS

  PROCEDURE add_job
  (p_jobid    IN jobs.empno%TYPE,
   p_jobtitle IN jobs.job%TYPE)
  IS
  BEGIN
  INSERT INTO jobs (empno, job)
  VALUES (p_jobid, p_jobtitle);
  END add_job;

  PROCEDURE upd_job
  (p_jobid    IN jobs.empno%TYPE,
   p_jobtitle IN jobs.job%TYPE)
  IS
    BEGIN
    UPDATE jobs
       SET job = p_jobtitle
     WHERE empno = p_jobid;
    IF SQL%NOTFOUND THEN
    RAISE_APPLICATION_ERROR(-20202,'No job updated.');
    END IF;
    END upd_job;

  PROCEDURE del_job
  (p_jobid IN jobs.empno%TYPE)
  IS
  BEGIN
  DELETE FROM jobs
   WHERE empno = p_jobid;
  IF SQL%NOTFOUND THEN
  RAISE_APPLICATION_ERROR (-20203,'No job deleted.');
  END IF;
  END del_job;

  FUNCTION q_job
  (p_jobid IN jobs.empno%TYPE)
  RETURN VARCHAR2
  IS
  v_jobtitle jobs.job%TYPE;
  BEGIN
  SELECT job
    INTO v_jobtitle
    FROM jobs
   WHERE empno = p_jobid;
  RETURN (v_jobtitle);
  END q_job;

END JOB_PACK;





DROP TABLE AUTOR_MUSICA;
DROP TABLE AUTOR;
DROP TABLE FAIXA;
DROP TABLE CD;
DROP TABLE GRAVADORA;
DROP TABLE MUSICA;
DROP TABLE CD_CATEGORIA;

CREATE TABLE AUTOR (
       aut_codigo           NUMBER primary key,
       aut_nome             VARCHAR(60) NOT NULL
);

CREATE TABLE GRAVADORA (
       grav_codigo          NUMBER PRIMARY KEY,
       grav_nome            VARCHAR(60) NOT NULL,
       grav_endereco        VARCHAR(60) NOT NULL,
       grav_telefone        VARCHAR(20) NOT NULL,
       grav_contato         VARCHAR(20) NOT NULL,
       grav_endsite         VARCHAR(80) NOT NULL
);

CREATE TABLE CD (
       cd_codigo            NUMBER primary key,
       cd_nome              VARCHAR(60) NOT NULL,
       cd_preco_venda       NUMBER(14,2) NOT NULL,
       cd_data_lancamento   DATE NULL,
       grav_codigo          NUMBER,
       cd_indicado          NUMBER
);

ALTER TABLE CD
       ADD  ( FOREIGN KEY (cd_indicado)
                             REFERENCES CD(cd_codigo) ) ;


ALTER TABLE CD
       ADD  ( FOREIGN KEY (grav_codigo)
                             REFERENCES GRAVADORA(grav_codigo) ) ;


CREATE TABLE CD_CATEGORIA (
       cat_codigo           NUMBER PRIMARY KEY,
       menor_preco          NUMBER(14,2) NOT NULL,
       maior_preco          NUMBER(14,2) NOT NULL
);

CREATE TABLE MUSICA (
       mus_codigo           NUMBER primary key,
       mus_nome             VARCHAR(60) NOT NULL,
       mus_duracao          NUMBER(6,2) NOT NULL
);

CREATE TABLE FAIXA (
       cd_codigo            NUMBER,
       mus_codigo           NUMBER,
       faixa_numero         NUMBER,
       PRIMARY KEY (cd_codigo, mus_codigo),
       FOREIGN KEY (cd_codigo) references CD (cd_codigo),
       FOREIGN KEY (mus_codigo) references musica (mus_codigo)
);

CREATE TABLE AUTOR_MUSICA (
       aut_codigo           NUMBER,
       mus_codigo           NUMBER,
       PRIMARY KEY (aut_codigo, mus_codigo)
);



ALTER TABLE AUTOR_MUSICA
       ADD  ( FOREIGN KEY (aut_codigo)
                             REFERENCES AUTOR (aut_codigo) ) ;


ALTER TABLE AUTOR_MUSICA
       ADD  ( FOREIGN KEY (mus_codigo)
                             REFERENCES musica(mus_codigo) ) ;

 ------------------------Bloco de teste de procedure-------------------------

 declare
 v_varchar varchar2(50);
 v_number number(10,3);

 BEGIN
 -----Coloque sua procedure aqui
 --exemplo_package.concatena_string('By',' Casseb',v_varchar);
 v_number := duracao_cd(1,v_number);


 -----Retornos
 ---Retorno texto
 if (v_varchar is not null) then
   dbms_output.put_line('Retorno Varchar2 = '||v_varchar);
 end if;
 ---Retorno numérico
 if (v_number is not null) then
   dbms_output.put_line('Retorno Number = '||v_number);
 end if;

 End;


 create or replace procedure localizar_cd (p_cd_nome in out cd.cd_nome%type, r_cd_preco out cd.cd_preco_venda%type)
   is
   begin
   select cd_nome, cd_preco_venda
   into p_cd_nome, r_cd_preco
   from cd
   where cd_nome = p_cd_nome;
   exception
     when NO_DATA_FOUND then
       dbms_output.put_line('Sem registro =-(');
     when TOO_MANY_ROWS then
       dbms_output.put_line('Mais de um registro');
     when OTHERS then
       dbms_output.put_line('Sei lá que erro que deu kkkkk');
 end;

 create table log_cd_preco (
   data_alteracao Date,
   usuario varchar(100),
   preco_antigo number(14,2),
   preco_atual number(14,2),
   cd number
 );

 create or replace Trigger log_cd_preco
   after update of cd_preco_venda on cd
   for each row
     begin
       insert into log_cd_preco (data_alteracao, usuario, preco_antigo, preco_atual,cd) values
         (sysdate,'casseb',:old.cd_preco_venda, :new.cd_preco_venda,:new.cd_codigo);
     end;

--------------------------Bloco em desuso----------------------------------


*/
---------------------------------Execute aqui-------------------------------






-----------------Final de arquivo, Commit implícito e demonstração de erros-------------------------
/
SHOW ERROR
commit;
