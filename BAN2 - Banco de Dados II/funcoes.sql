-- MODULO DE LOGIN

-- 1) Fazer o login
-- Dados o nome de usuário e a senha, vai retornar o nome e o id do usuário caso exista.

create or replace function realizarLogin(usuarioP varchar(25), senhaP varchar(8)) returns table(codp_ int,
nome_ varchar(255)) as
$$
declare
	res record default NULL;
	flag boolean default false;
begin
    for res in select codP, nome from passageiros where usuario = usuarioP and senha = senhaP limit 1 loop
		codp_ := res.codp;
		nome_ := res.nome;
		flag := true;
		return next;
    end loop;
	if (flag is false) then
		raise exception 'Usuário não encontrado';
	end if;
end;
$$
language plpgsql;

select * from realizarLogin('admin','123')

----------------------------------------------------------------------------------------

-- MODULO DE CIDADES

-- 1) Buscar aeroportos de uma cidade
-- Dado o código de uma cidade vai retornar todos os aeroportos dessa cidade

create or replace function buscarAeroportosCidade(codcP int) returns table(codap_ int, nome_ varchar(255)) as
$$
declare
	res record default NULL;
begin
    for res in select codap, nome from aeroportos where codc = codcP loop
		codap_ := res.codap;
		nome_ := res.nome;
		return next;
    end loop;
end;
$$
language plpgsql;

select * from buscarAeroportosCidade(2);

-- 2) Buscar cidades do sistema
-- Retorna todas as informações da tabela de cidades

create or replace function buscarCidades() returns table (codc_ int, nome_ varchar(50)) as
$$
declare
	res record default NULL;
begin
    return query select * from cidades order by nome;
end;
$$
language plpgsql;


select * from buscarCidades();

----------------------------------------------------------------------------------------

-- MODULO DE COMPRAR

-- 1) Dados o codigo do voo, retornar as informações referentes aos trechos dele

create or replace function buscarTrechosVoo(codvP int) returns table (codtv_ int,codt_ int, codc_origem int, codc_destino int, codae_ int ) as
$$
begin
    return query select codtv, codt, origem, destino, codae from trechosVoo natural join trechos where codv = codvP;
end;
$$
language plpgsql;

select * from buscarTrechosVoo(2);

create or replace function buscarTrechosVooCompleto (codtp int) returns table (codtr_ int, data_ timestamp, origem_ int, destino_ int, codae_ int) as
$$
begin
	return query select * from trechos where codt in (select codt_ as codt from buscartrechosvoo(codtp));
end;
$$
language plpgsql;


-- 2) Dados:
-- codigo da cidade origem
-- codigo da cidade de destino
-- data da viagem
-- chegada prevista

-- Retornar as informações da tabela voos que passam nesse filtro

create or replace function filtrarVoos(codcOrigemP int, codcDestinoP int, dataP timestamp, chegadaPrevistaP timestamp) returns table (codv_ int) as
$$
declare
	dataSaidaMax timestamp;
	dataChegadaMin timestamp;
	dataChegadaMax timestamp;
	origens record;
	destinos record;
begin
	dataSaidaMax := dataP + interval '2 hours';
	--raise exception 'dataSaidaMax: %', dataSaidaMax;
	dataChegadaMin := chegadaPrevistaP - interval '1 hour';
	dataChegadaMin := dataChegadaMin - interval '30 minutes';
	-- raise exception 'dataChegadaMin: %', dataChegadaMin;
	dataChegadaMax := chegadaPrevistaP + interval '1 hour';
	dataChegadaMax := dataChegadaMax + interval '30 minutes';
	-- raise exception 'dataChegadaMax: %', dataChegadaMax;
	return query select codv from voos where origem in (select codap from aeroportos where codc = codcOrigemP) and destino in (select codap from aeroportos where codc = codcDestinoP) and data <= dataSaidaMax and data >= dataP and chegadaprevista >= dataChegadaMin and chegadaprevista <= dataChegadaMax;
end;
$$
language plpgsql;

select * from filtrarVoos(3,2,'2021-03-16 10:00:00','2021-03-16 13:30:00');

-- 3) Dado o código de um trecho, retornar os assentos livres

create or replace function buscarAssentosTrecho(codtP int) returns table (coda_ int, codcl_ int, reservado_ boolean) as
$$
begin
	return query select coda, codcl, reservado from assentos where codt = codtP order by codcl;
end;
$$
language plpgsql;


create or replace function buscarAssentosLivres(codtP int) returns table (coda_ int, codcl_ int) as
$$
begin
	return query select coda, codcl from assentos where codt = codtP and reservado = false order by codcl;
end;
$$
language plpgsql;

create or replace function buscarAssentosOcupados(codtP int) returns table (coda_ int, codcl int) as
$$
begin
	return query select coda, codcl from assentos where codt = 1 and reservado = true order by codcl;
end;
$$
language plpgsql;

-- 4) Dado o código do assento, código do passageiro e a data, realizar a reserva

create sequence id_reserva;

create or replace function gerarIdReserva() returns table (novo_id bigint) as
$$
begin
	return query select nextval('id_reserva');
end;
$$
language plpgsql;

create or replace function isAssentoVago(codaP int) returns table (resul boolean) as
$$
begin
	return query select reservado from assentos where coda = codaP;
end;
$$
language plpgsql;

create or replace function reservarAssento(codaP int) returns void as
$$
begin
	update assentos set reservado = true where coda = codaP;
end;
$$
language plpgsql;

create or replace function realizarReserva(codaP int, codpP int, dataP timestamp) returns void as
$$
declare
	isReservado boolean default false;
	idNovo int;
begin
	select * from isAssentoVago(codaP) into isReservado;
	if(isReservado is false) then
		select * from gerarIdReserva() into idNovo;
		insert into reservas values (idNovo,dataP,codpP,codaP,false);
		select reservarAssento(codaP);
	end if;
end;
$$
language plpgsql;

----------------------------------------------------------------------------------------

-- MODULO DE CHECKIN

-- 1) Dado o código do passageiro, listar suas reservas


select * from reservas where codp = 1;
select * from assentos where coda = 70;
select * from trechos where codt = 1;

create or replace function buscarTrechoDoAssento(codaP int) returns table (codt_ int) as
$$
begin
	return query select codt from assentos where coda = codaP;
end;
$$
language plpgsql;

create or replace function buscarOrigemDestinoTrecho(codtP int) returns table (origem_ int, destino_ int) as
$$
begin
	return query select origem,destino from trechos where codt = codtP;
end;
$$
language plpgsql;

create or replace function listar_reservas(codpP int) returns table (codr_ int, data_ timestamp, coda_ int, confirmada_ boolean,coda_origem_ int, coda_destino_ int) as
$$
declare
	assento int default -1;
	res record default NULL;
	res2 record default NULL;
begin
	for res in select * from reservas where codp = codpP loop
		select * from buscarTrechoDoAssento(res.coda) into assento;
		if(assento = -1) then
			raise exception 'Assento não encontrado';
		else
			for res2 in select * from buscarOrigemDestinoTrecho(assento) loop
				if (res2.origem_ = -1) then
					raise exception 'Erro ao buscar aeroporto de origem';
				else
					select data from trechos where codt = res2.origem_ into data_;
					if (res2.destino_ = -1) then
						raise exception 'Erro ao buscar aeroporto de origem';
					else
						coda_origem_ := res2.origem_;
						coda_destino_ := res2.destino_;
						codr_ := res.codr;
						coda_ := res.coda;
						confirmada_ := res.confirmada;
						return next;
					end if;
				end if;
			end loop;
		end if;
	end loop;
end;
$$
language plpgsql;

create or replace function buscar_info_aeroporto(codapP int) returns table (nome_ varchar(255),codc_ int) as
$$
begin
	return query select nome,codc from aeroportos where codap = codapP;
end;
$$
language plpgsql;

-- 2) Dado o código da reserva, realizar o checkin da reserva

create or replace function realizarCheckIn(codrP int) returns void as
$$
begin
	update reservas set confirmada = true where codr = codrP;
end;
$$
language plpgsql;



----------------------------------------------------------------------------------------

-- BACK END

create sequence id_assento;

create or replace function criarAssentosTrecho(codT int) returns void as
$$
declare fator int;
begin
	select floor(random() * 4 + 1) into fator;
	for i in 1..fator loop
		insert into assentos (select nextval('id_assento'),codT,3,false);
	end loop;
	for i in 1..12 loop
		insert into assentos (select nextval('id_assento'),codT,2,false);
	end loop;
	for i in 1..18 loop
		insert into assentos (select nextval('id_assento'),codT,1,false);
	end loop;
end;
$$
language plpgsql;


