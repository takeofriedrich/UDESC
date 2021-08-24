create database avaliacaoODAW;
use avaliacaoODAW;

create table usuario(
    id serial primary key,
    usuario varchar(31),
    senha varchar(63)
);

insert into usuario (usuario,senha) values ('admin','123');

create table treinos(
    id serial primary key,
    nome varchar(255),
    repeticoes int,
    series int,
    carga int,
    data date
);

insert into treinos (nome,repeticoes,series,carga,data) values ('Supino inclinado',3,15,30,'2021-03-25 17:00');
insert into treinos (nome,repeticoes,series,carga,data) values ('Supino reto',4,10,35,'2021-03-25 17:10');
insert into treinos (nome,repeticoes,series,carga,data) values ('Triceps no supino',3,15,40,'2021-03-25 17:30');

