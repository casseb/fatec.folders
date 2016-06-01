
----------------Preparando Banco-----------------------------------------

/*alter session set nls_date_format = 'DD/MM/YYYY HH24:MI:SS';*/

----------------------Instruções iniciais--------------------------------

clear scr

-----------------------Consultando todas as tabelas-----------------------

select
rownum, table_name from all_tables
where owner = 'JOGO';

--desc ser_servico

-----------------------Consultando todas as constraints--------------------

/*
select
rownum, constraint_name from all_cons_columns
where owner = '&Banco';
*/

-----------------------Consultando todas as Sequences--------------------

/*
select
rownum, sequence_name from all_sequences
where sequence_owner = 'JOGO';
*/

-----------------------Apagando Sequence--------------------------------
/*
drop sequence &SequenceName;
*/

---------------------Consultando todo o conteudo da tabela--------------------

/*
select
* from &Tabela;
*/

---------------------Limpando uma tabela completamente--------------------------
/*
delete from
&Tabela;
*/
-------------------------------Instruções---------------------------------
/*
insert into
cta_conta
(CTA_NOME,CTA_SENHA,CTA_DATA_EXPIRACAO) values
('Batman','BecauseIambatman',TO_DATE('2016-05-17', 'YYYY-MM-DD'));

insert into
cta_conta
(CTA_NOME,CTA_SENHA,CTA_DATA_EXPIRACAO) VALUES
('PUNISHER','DAREDEVIL2SEASON',TO_DATE('2016-05-17', 'YYYY-MM-DD'));

insert into
cta_conta
(CTA_NOME,CTA_SENHA,CTA_DATA_EXPIRACAO) values
('Spiderman','Heyguys', TO_DATE('2016-05-17', 'YYYY-MM-DD'));

insert into
pta_pista
(PTA_NOME,PTA_DESCRICAO,PTA_COMPRIMENTO,PTA_TIPO) VALUES
('Gotham City','Pista do batman, ele corre nela BECAUSE I AM BATMAN',143,'A');

insert into
pta_pista
(PTA_NOME,PTA_DESCRICAO,PTA_COMPRIMENTO,PTA_TIPO) VALUES
('Hell´s Kitchen','Punisher e mais importante que o dono da pista',54,'B');

insert into
pta_pista
(PTA_NOME,PTA_DESCRICAO,PTA_COMPRIMENTO,PTA_TIPO) VALUES
('QUEENS','Tenho dever de casa',29,'C');

insert into
cor_corrida
(cta_nome,pta_nome,cor_tempo) values
('Batman','QUEENS',1);

insert into
cor_corrida
(cta_nome,pta_nome,cor_tempo) values
('PUNISHER','Gotham City',42);

insert into
cor_corrida
(cta_nome,pta_nome,cor_tempo) values
('Spiderman','Hell´s Kitchen',13);

insert into
cor_corrida
(cta_nome,pta_nome,cor_tempo) values
('PUNISHER','QUEENS',42);

insert into
cor_corrida
(cta_nome,pta_nome,cor_tempo) values
('Spiderman','Gotham City',20);

insert into
cpa_compra
(cta_nome,cpa_data_hora,cpa_valor_total,cpa_status) values
('Batman',TO_DATE('24/05/2016 19:23:12','DD/MM/YYYY HH24:MI:SS'),99999.99,'PG');

insert into
cpa_compra
(cta_nome,cpa_data_hora,cpa_valor_total,cpa_status) values
('Spiderman',TO_DATE('24/04/2016 20:23:00','DD/MM/YYYY HH24:MI:SS'),1.99,'NPG');

insert into
cpa_compra
(cta_nome,cpa_data_hora,cpa_valor_total,cpa_status) values
('PUNISHER',TO_DATE('02/02/1996 08:23:12','DD/MM/YYYY HH24:MI:SS'),1.99,'PG');


insert into
cpa_compra
(cta_nome,cpa_data_hora,cpa_valor_total,cpa_status) values
('PUNISHER',TO_DATE('09/10/1985 22:23:12','DD/MM/YYYY HH24:MI:SS'),0.99,'PG');


insert into
cpa_compra
(cta_nome,cpa_data_hora,cpa_valor_total,cpa_status) values
('Batman',TO_DATE('10/08/1989 22:23:12','DD/MM/YYYY HH24:MI:SS'),1.99,'PG');

---------------------------     Lambança do CURRVAL      ------------------------------

------------------   Item 1

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Batmovel','Carro do batman',99999.99,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('19/10/2016','DD/MM/YYYY'));

insert into
vei_veiculo
(ite_codigo,vei_potencia_motor,vei_estabilidade,vei_eixos,vei_velocidade_maxima,vei_quantidade_marchas) values
(ITE_CODIGO_SQ.CURRVAL,95185,5,3,99999,0);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('Batman',TO_DATE('24/05/2016 19:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,99999.99);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('PUNISHER',TO_DATE('09/10/1985 22:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,99999.99);

------------------   Item 2

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Spidermovel','Cópia barata do carro do batman',1.99,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('20/05/2016','DD/MM/YYYY'));

insert into
vei_veiculo
(ite_codigo,vei_potencia_motor,vei_estabilidade,vei_eixos,vei_velocidade_maxima,vei_quantidade_marchas) values
(ITE_CODIGO_SQ.CURRVAL,1,1,1,1,2);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('Batman',TO_DATE('24/05/2016 19:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,99999.99);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('PUNISHER',TO_DATE('09/10/1985 22:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,99999.99);

------------------   Item 3

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Herbie','Fusquinha mais rapido do mund0',0.99,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('20/10/2017','DD/MM/YYYY'));

insert into
vei_veiculo
(ite_codigo,vei_potencia_motor,vei_estabilidade,vei_eixos,vei_velocidade_maxima,vei_quantidade_marchas) values
(ITE_CODIGO_SQ.CURRVAL,20,1,2,120,5);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('Spiderman',TO_DATE('24/04/2016 20:23:00','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('PUNISHER',TO_DATE('02/02/1996 08:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

------------------   Item 4

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Advocacia','A justiça é cega',100,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('20/10/2016','DD/MM/YYYY'));

insert into
ser_servico(ite_codigo,ser_contrato) values
(ITE_CODIGO_SQ.CURRVAL,'Aceito os termos deste contrato do cego murdok');

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('Spiderman',TO_DATE('24/04/2016 20:23:00','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('PUNISHER',TO_DATE('02/02/1996 08:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

------------------   Item 5

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Wayne Enterprises','Broken',50,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('05/10/2016','DD/MM/YYYY'));

insert into
ser_servico(ite_codigo,ser_contrato) values
(ITE_CODIGO_SQ.CURRVAL,'Batcontrato');

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('Batman',TO_DATE('10/08/1989 22:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('PUNISHER',TO_DATE('09/10/1985 22:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

------------------   Item 6

insert into
ite_item
(ite_codigo,ite_nome,ite_descricao,ite_valor,ite_data_criacao,ite_data_expiracao) values
(ITE_CODIGO_SQ.NEXTVAL,'Planeta Diario','Superman',50,TO_DATE('19/05/2016','DD/MM/YYYY'),TO_DATE('05/10/2016','DD/MM/YYYY'));

insert into
ser_servico(ite_codigo,ser_contrato) values
(ITE_CODIGO_SQ.CURRVAL,'Super notícias');

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('Batman',TO_DATE('10/08/1989 22:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

insert into
cit_item_compra
(cta_nome,cpa_data_hora,ite_codigo,cit_valor) values
('PUNISHER',TO_DATE('09/10/1985 22:23:12','DD/MM/YYYY HH24:MI:SS'),ITE_CODIGO_SQ.CURRVAL,1.99);

*/


commit;
