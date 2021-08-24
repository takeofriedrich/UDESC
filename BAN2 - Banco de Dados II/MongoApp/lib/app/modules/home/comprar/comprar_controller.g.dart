// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'comprar_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $ComprarController = BindInject(
  (i) => ComprarController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$ComprarController on _ComprarControllerBase, Store {
  final _$origemAtom = Atom(name: '_ComprarControllerBase.origem');

  @override
  Cidade get origem {
    _$origemAtom.reportRead();
    return super.origem;
  }

  @override
  set origem(Cidade value) {
    _$origemAtom.reportWrite(value, super.origem, () {
      super.origem = value;
    });
  }

  final _$destinoAtom = Atom(name: '_ComprarControllerBase.destino');

  @override
  Cidade get destino {
    _$destinoAtom.reportRead();
    return super.destino;
  }

  @override
  set destino(Cidade value) {
    _$destinoAtom.reportWrite(value, super.destino, () {
      super.destino = value;
    });
  }

  final _$dataAtom = Atom(name: '_ComprarControllerBase.data');

  @override
  DateTime get data {
    _$dataAtom.reportRead();
    return super.data;
  }

  @override
  set data(DateTime value) {
    _$dataAtom.reportWrite(value, super.data, () {
      super.data = value;
    });
  }

  final _$horarioSaidaAtom = Atom(name: '_ComprarControllerBase.horarioSaida');

  @override
  TimeOfDay get horarioSaida {
    _$horarioSaidaAtom.reportRead();
    return super.horarioSaida;
  }

  @override
  set horarioSaida(TimeOfDay value) {
    _$horarioSaidaAtom.reportWrite(value, super.horarioSaida, () {
      super.horarioSaida = value;
    });
  }

  final _$horarioChegadaAtom =
      Atom(name: '_ComprarControllerBase.horarioChegada');

  @override
  TimeOfDay get horarioChegada {
    _$horarioChegadaAtom.reportRead();
    return super.horarioChegada;
  }

  @override
  set horarioChegada(TimeOfDay value) {
    _$horarioChegadaAtom.reportWrite(value, super.horarioChegada, () {
      super.horarioChegada = value;
    });
  }

  final _$_ComprarControllerBaseActionController =
      ActionController(name: '_ComprarControllerBase');

  @override
  dynamic definirData(DateTime data) {
    final _$actionInfo = _$_ComprarControllerBaseActionController.startAction(
        name: '_ComprarControllerBase.definirData');
    try {
      return super.definirData(data);
    } finally {
      _$_ComprarControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic definirHorarioSaida(TimeOfDay horario) {
    final _$actionInfo = _$_ComprarControllerBaseActionController.startAction(
        name: '_ComprarControllerBase.definirHorarioSaida');
    try {
      return super.definirHorarioSaida(horario);
    } finally {
      _$_ComprarControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic definirHorarioChegada(TimeOfDay horario) {
    final _$actionInfo = _$_ComprarControllerBaseActionController.startAction(
        name: '_ComprarControllerBase.definirHorarioChegada');
    try {
      return super.definirHorarioChegada(horario);
    } finally {
      _$_ComprarControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
origem: ${origem},
destino: ${destino},
data: ${data},
horarioSaida: ${horarioSaida},
horarioChegada: ${horarioChegada}
    ''';
  }
}
