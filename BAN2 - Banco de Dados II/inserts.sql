insert into cidades values(1,'Joinville');
insert into cidades values(2,'Curitiba');
insert into cidades values(3,'Florianopolis');
insert into cidades values(4,'São Paulo');

insert into aeroportos values(1,'Lauro Carneiro de Loyola',1);
insert into aeroportos values(2,'Afonso Pena',2);
insert into aeroportos values(3,'Bacacheri',2);
insert into aeroportos values(4,'Hercílio Luz',3);
insert into aeroportos values(5,'Congonhas',4);
insert into aeroportos values(6,'Guarulhos',4);
insert into aeroportos values(7,'Viracopos',4);

insert into classes values (1,'Economica'); 
insert into classes values (2,'Executiva'); 
insert into classes values (3,'Primeira-Classe');

insert into modelos values (1,'Airbus A320');
insert into modelos values (2,'Boeing 737');
insert into modelos values (3,'Boeing 777');

insert into aeronaves values (1,56,1);
insert into aeronaves values (2,52,1);
insert into aeronaves values (3,48,1);
insert into aeronaves values (4,44,1);
insert into aeronaves values (5,40,1);

insert into trechos values (1,'2021-03-01 10:00:00',4,1,1); -- Flor/Join
insert into trechos values (2,'2021-03-01 11:00:00',1,2,2); -- Join/Cur
insert into trechos values (3,'2021-03-01 12:00:00',2,5,3); -- Cur/Sp(cong)
insert into trechos values (4,'2021-03-01 12:00:00',2,6,4); -- Cur/Sp(guar)
insert into trechos values (5,'2021-03-01 10:00:00',4,2,5); -- Flor/Cur

insert into voos values (1,'2021-03-01 10:00:00',4,2,'2021-03-01 12:00:00'); -- Flor/Cur
insert into trechosVoo values (1,1,1); -- Flor/Join
insert into trechosVoo values (2,1,2); -- Join/Cur

insert into voos values (2,'2021-03-01 10:00:00',4,5,'2021-03-01 13:30:00'); -- Flor/Sp
insert into trechosVoo values (3,2,1); -- Flor/Join
insert into trechosVoo values (4,2,2); -- Join/Cur
insert into trechosVoo values (5,2,3); -- Cur/Sp(cong)

insert into voos values (3,'2021-03-01 10:00:00',4,6,'2021-03-01 13:30:00'); -- Flor/Sp
insert into trechosVoo values (6,3,1); -- Flor/Join
insert into trechosVoo values (7,3,2); -- Join/Cur
insert into trechosVoo values (8,3,4); -- Cur/Sp(cong)

insert into voos values (4,'2021-03-01 10:00:00',2,6,'2021-03-01 11:30:00'); -- Jlle/Sp
insert into trechosVoo values (9,4,2); -- Join/Cur
insert into trechosVoo values (10,4,4); -- Cur/Sp(guar)

