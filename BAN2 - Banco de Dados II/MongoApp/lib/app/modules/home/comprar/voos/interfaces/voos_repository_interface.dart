import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/voo.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';

abstract class IVoosRepository implements Disposable {
  Future<List<Voo>> listarVoos(Cidade origem, Cidade destino, DateTime data,
      TimeOfDay horarioSaida, TimeOfDay horarioChegada);
  Future<Voo> select(int codv);
}
