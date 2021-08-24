// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'cidades_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $CidadesController = BindInject(
  (i) => CidadesController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$CidadesController on _CidadesControllerBase, Store {
  final _$cidadesAtom = Atom(name: '_CidadesControllerBase.cidades');

  @override
  List<Cidade> get cidades {
    _$cidadesAtom.reportRead();
    return super.cidades;
  }

  @override
  set cidades(List<Cidade> value) {
    _$cidadesAtom.reportWrite(value, super.cidades, () {
      super.cidades = value;
    });
  }

  final _$buscarCidadesAsyncAction =
      AsyncAction('_CidadesControllerBase.buscarCidades');

  @override
  Future<void> buscarCidades() {
    return _$buscarCidadesAsyncAction.run(() => super.buscarCidades());
  }

  @override
  String toString() {
    return '''
cidades: ${cidades}
    ''';
  }
}
