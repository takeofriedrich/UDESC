create table estilos(
  id serial,
  nome varchar(30),
  PRIMARY KEY (id)
);

create table categorias(
  id serial,
  nome varchar(30),
  preço float,
  PRIMARY KEY (id)
);

create table filmes(
  id serial,
  titulo varchar(50),
  duracao int,
  ano int,
  categoria int,
  estilo int,
  PRIMARY KEY (id),
  FOREIGN KEY (categoria) references categorias(id),
  FOREIGN KEY (estilo) references estilos(id)
);

create table copias(
  id serial,
  filme int,
  midia varchar(30),
  tipo varchar(30),
  PRIMARY KEY (id,filme),
  FOREIGN KEY (filme) references filmes(id)
);

create table funcionarios(
  id serial,
  nome varchar(30),
  endereço varchar(30),
  fone varchar(10),
  cidade varchar(30),
  salario float,
  turno varchar(1),
  cpf varchar(11),
  PRIMARY KEY (id)
);

create table clientes(
  id serial,
  nome varchar(30),
  endereço varchar(30),
  fone varchar(10),
  cidade varchar(30),
  responsavel int,
  cpf int,
  PRIMARY KEY (id),
  FOREIGN KEY (responsavel) references funcionarios(id)
);

create table reservas(
  id int,
  filme int,
  cliente int,
  dataR date,
  dataPD date,
  funcionario int,
  dataRes date,
  PRIMARY KEY (id,filme,cliente,dataR),
  FOREIGN KEY (id,filme) references copias (id,filme),
  FOREIGN KEY (cliente) references clientes(id),
  FOREIGN KEY (funcionario) references funcionarios(id)
);

create table locações(
  id int,
  filme int,
  cliente int,
  dataR date,
  dataPD date,
  funcionario int,
  dataRes date,
  PRIMARY KEY (id,filme,cliente,dataR),
  FOREIGN KEY (id,filme,cliente,dataR) references reservas,
  FOREIGN KEY (funcionario) references funcionarios(id)
);
