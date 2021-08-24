// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'selecionar_destino_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $SelecionarDestinoController = BindInject(
  (i) => SelecionarDestinoController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$SelecionarDestinoController on _SelecionarDestinoControllerBase, Store {
  final _$cidadesDisponiveisAtom =
      Atom(name: '_SelecionarDestinoControllerBase.cidadesDisponiveis');

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

  final _$indexAtom = Atom(name: '_SelecionarDestinoControllerBase.index');

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
      AsyncAction('_SelecionarDestinoControllerBase.buscarCidades');

  @override
  Future<void> buscarCidades() {
    return _$buscarCidadesAsyncAction.run(() => super.buscarCidades());
  }

  final _$_SelecionarDestinoControllerBaseActionController =
      ActionController(name: '_SelecionarDestinoControllerBase');

  @override
  dynamic definirCidade() {
    final _$actionInfo = _$_SelecionarDestinoControllerBaseActionController
        .startAction(name: '_SelecionarDestinoControllerBase.definirCidade');
    try {
      return super.definirCidade();
    } finally {
      _$_SelecionarDestinoControllerBaseActionController
          .endAction(_$actionInfo);
    }
  }

  @override
  dynamic selectIndex(int index) {
    final _$actionInfo = _$_SelecionarDestinoControllerBaseActionController
        .startAction(name: '_SelecionarDestinoControllerBase.selectIndex');
    try {
      return super.selectIndex(index);
    } finally {
      _$_SelecionarDestinoControllerBaseActionController
          .endAction(_$actionInfo);
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
