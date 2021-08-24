// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'selecionar_origem_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $SelecionarOrigemController = BindInject(
  (i) => SelecionarOrigemController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$SelecionarOrigemController on _SelecionarOrigemControllerBase, Store {
  final _$cidadesDisponiveisAtom =
      Atom(name: '_SelecionarOrigemControllerBase.cidadesDisponiveis');

  @override
  List<Cidade> get cidadesDisponiveis {
    _$cidadesDisponiveisAtom.reportRead();
    return super.cidadesDisponiveis;
  }

  @override
  set cidadesDisponiveis(List<Cidade> value) {
    _$cidadesDisponiveisAtom.reportWrite(value, super.cidadesDisponiveis, () {
      super.cidadesDisponiveis = value;
    });
  }

  final _$indexAtom = Atom(name: '_SelecionarOrigemControllerBase.index');

  @override
  int get index {
    _$indexAtom.reportRead();
    return super.index;
  }

  @override
  set index(int value) {
    _$indexAtom.reportWrite(value, super.index, () {
      super.index = value;
    });
  }

  final _$buscarCidadesAsyncAction =
      AsyncAction('_SelecionarOrigemControllerBase.buscarCidades');

  @override
  Future<void> buscarCidades() {
    return _$buscarCidadesAsyncAction.run(() => super.buscarCidades());
  }

  final _$_SelecionarOrigemControllerBaseActionController =
      ActionController(name: '_SelecionarOrigemControllerBase');

  @override
  dynamic definirCidade() {
    final _$actionInfo = _$_SelecionarOrigemControllerBaseActionController
        .startAction(name: '_SelecionarOrigemControllerBase.definirCidade');
    try {
      return super.definirCidade();
    } finally {
      _$_SelecionarOrigemControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic selectIndex(int index) {
    final _$actionInfo = _$_SelecionarOrigemControllerBaseActionController
        .startAction(name: '_SelecionarOrigemControllerBase.selectIndex');
    try {
      return super.selectIndex(index);
    } finally {
      _$_SelecionarOrigemControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
cidadesDisponiveis: ${cidadesDisponiveis},
index: ${index}
    ''';
  }
}
