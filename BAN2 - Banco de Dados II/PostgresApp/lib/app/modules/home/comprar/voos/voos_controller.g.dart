// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'voos_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $VoosController = BindInject(
  (i) => VoosController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$VoosController on _VoosControllerBase, Store {
  final _$voosAtom = Atom(name: '_VoosControllerBase.voos');

  @override
  List<Voo> get voos {
    _$voosAtom.reportRead();
    return super.voos;
  }

  @override
  set voos(List<Voo> value) {
    _$voosAtom.reportWrite(value, super.voos, () {
      super.voos = value;
    });
  }

  final _$selecionadoAtom = Atom(name: '_VoosControllerBase.selecionado');

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

  final _$_VoosControllerBaseActionController =
      ActionController(name: '_VoosControllerBase');

  @override
  dynamic alterarVoos(List<Voo> voos) {
    final _$actionInfo = _$_VoosControllerBaseActionController.startAction(
        name: '_VoosControllerBase.alterarVoos');
    try {
      return super.alterarVoos(voos);
    } finally {
      _$_VoosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic selecionarVoo(int index) {
    final _$actionInfo = _$_VoosControllerBaseActionController.startAction(
        name: '_VoosControllerBase.selecionarVoo');
    try {
      return super.selecionarVoo(index);
    } finally {
      _$_VoosControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
voos: ${voos},
selecionado: ${selecionado}
    ''';
  }
}
