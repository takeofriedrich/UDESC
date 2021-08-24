create table passageiros(
    codP int primary key,
    nome varchar(255),
    usuario varchar(25),
    senha varchar(8)
);

create table cidades(
    codC int primary key,
    nome varchar(50)
);

create table aeronaves(
    codAe int  primary key,
    capacidade int,
    modelo int references modelos
);

create table aeroportos(
    codAp int  primary key,
    nome varchar(255),
    codC int references cidades
);

create table classes(
    codCl int  primary key,
    nome varchar(50)
);

create table trechos(
    codT int primary key,
    data timestamp,
    origem int  references aeroportos,
    destino int references aeroportos,
    codAe int references aeronaves
);

create table assentos(
    codA int primary key,
    codT int  references trechos,
    codCl int references classes,
    reservado boolean
);

create table voos(
    codV int primary key,
    data timestamp,
    origem int references aeroportos,
    destino int references aeroportos,
    chegadaPrevista timestamp
);

create table trechosVoo(
    codTv int primary key,
    codV int references voos,
    codT int references trechos
);

create table reservas(
    codR int primary key,
    data timestamp,
    codP int references passageiros,
    codA int references assentos,
    confirmada boolean
);

create table modelos(
    codmod int primary key,
    nome varchar(255)
);