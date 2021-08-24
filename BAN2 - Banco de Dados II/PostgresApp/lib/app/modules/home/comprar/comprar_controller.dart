import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/interfaces/voos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/voos_controller.dart';
import 'package:flutter/material.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'voos/models/voo.dart';

part 'comprar_controller.g.dart';

@Injectable()
class ComprarController = _ComprarControllerBase with _$ComprarController;

abstract class _ComprarControllerBase with Store {
  @observable
  Cidade origem;

  @observable
  Cidade destino;

  @observable
  DateTime data;

  @observable
  TimeOfDay horarioSaida;

  @observable
  TimeOfDay horarioChegada;

  @action
  definirData(DateTime data) => this.data = data;

  @action
  definirHorarioSaida(TimeOfDay horario) => horarioSaida = horario;

  @action
  definirHorarioChegada(TimeOfDay horario) => horarioChegada = horario;

  Future<void> filtrar() async {
    if (origem == null) throw Exception('Selecione a cidade origem!');
    if (destino == null) throw Exception('Selecione a cidade destino!');
    if (data == null) throw Exception('Selecione a data!');
    if (horarioSaida == null) throw Exception('Selecione o horário de saída!');
    if (horarioChegada == null)
      throw Exception('Selecione o horário de chegada!');

    List<Voo> voos = await Modular.get<IVoosRepository>()
        .listarVoos(origem, destino, data, horarioSaida, horarioChegada);
    if (voos.isNotEmpty) {
      Modular.get<VoosController>().alterarVoos(voos);
      Modular.to.pushReplacementNamed('/home/comprar/voos');
    } else {
      throw Exception('Nenhum voo encontrado!');
    }
  }
}
