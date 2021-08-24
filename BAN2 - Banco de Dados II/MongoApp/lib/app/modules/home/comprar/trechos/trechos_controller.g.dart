// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'trechos_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $TrechosController = BindInject(
  (i) => TrechosController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$TrechosController on _TrechosControllerBase, Store {
  final _$trechosAtom = Atom(name: '_TrechosControllerBase.trechos');

  @override
  List<Trecho> get trechos {
    _$trechosAtom.reportRead();
    return super.trechos;
  }

  @override
  set trechos(List<Trecho> value) {
    _$trechosAtom.reportWrite(value, super.trechos, () {
      super.trechos = value;
    });
  }

  final _$assentosSelecionadosAtom =
      Atom(name: '_TrechosControllerBase.assentosSelecionados');

  @override
  Map<int, int> get assentosSelecionados {
    _$assentosSelecionadosAtom.reportRead();
    return super.assentosSelecionados;
  }

  @override
  set assentosSelecionados(Map<int, int> value) {
    _$assentosSelecionadosAtom.reportWrite(value, super.assentosSelecionados,
        () {
      super.assentosSelecionados = value;
    });
  }

  final _$_TrechosControllerBaseActionController =
      ActionController(name: '_TrechosControllerBase');

  @override
  dynamic definirTrechos(List<Trecho> trechos) {
    final _$actionInfo = _$_TrechosControllerBaseActionController.startAction(
        name: '_TrechosControllerBase.definirTrechos');
    try {
      return super.definirTrechos(trechos);
    } finally {
      _$_TrechosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic selecionarAssento(int trecho, int assento, int inicial) {
    final _$actionInfo = _$_TrechosControllerBaseActionController.startAction(
        name: '_TrechosControllerBase.selecionarAssento');
    try {
      return super.selecionarAssento(trecho, assento, inicial);
    } finally {
      _$_TrechosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
trechos: ${trechos},
assentosSelecionados: ${assentosSelecionados}
    ''';
  }
}
