// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'assentos_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $AssentosController = BindInject(
  (i) => AssentosController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$AssentosController on _AssentosControllerBase, Store {
  final _$assentosAtom = Atom(name: '_AssentosControllerBase.assentos');

  @override
  Map<int, bool> get assentos {
    _$assentosAtom.reportRead();
    return super.assentos;
  }

  @override
  set assentos(Map<int, bool> value) {
    _$assentosAtom.reportWrite(value, super.assentos, () {
      super.assentos = value;
    });
  }

  final _$trechoAtom = Atom(name: '_AssentosControllerBase.trecho');

  @override
  Trecho get trecho {
    _$trechoAtom.reportRead();
    return super.trecho;
  }

  @override
  set trecho(Trecho value) {
    _$trechoAtom.reportWrite(value, super.trecho, () {
      super.trecho = value;
    });
  }

  final _$selecionadoAtom = Atom(name: '_AssentosControllerBase.selecionado');

  @override
  int get selecionado {
    _$selecionadoAtom.reportRead();
    return super.selecionado;
  }

  @override
  set selecionado(int value) {
    _$selecionadoAtom.reportWrite(value, super.selecionado, () {
      super.selecionado = value;
    });
  }

  final _$_AssentosControllerBaseActionController =
      ActionController(name: '_AssentosControllerBase');

  @override
  dynamic definirAssentos(Map<int, bool> assentos) {
    final _$actionInfo = _$_AssentosControllerBaseActionController.startAction(
        name: '_AssentosControllerBase.definirAssentos');
    try {
      return super.definirAssentos(assentos);
    } finally {
      _$_AssentosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic definirTrecho(Trecho trecho) {
    final _$actionInfo = _$_AssentosControllerBaseActionController.startAction(
        name: '_AssentosControllerBase.definirTrecho');
    try {
      return super.definirTrecho(trecho);
    } finally {
      _$_AssentosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic selecionar(int poltrona) {
    final _$actionInfo = _$_AssentosControllerBaseActionController.startAction(
        name: '_AssentosControllerBase.selecionar');
    try {
      return super.selecionar(poltrona);
    } finally {
      _$_AssentosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
assentos: ${assentos},
trecho: ${trecho},
selecionado: ${selecionado}
    ''';
  }
}
