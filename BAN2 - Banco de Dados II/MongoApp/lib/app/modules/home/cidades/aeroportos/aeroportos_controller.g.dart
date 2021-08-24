// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'aeroportos_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $AeroportosController = BindInject(
  (i) => AeroportosController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$AeroportosController on _AeroportosControllerBase, Store {
  final _$cidadeAtom = Atom(name: '_AeroportosControllerBase.cidade');

  @override
  Cidade get cidade {
    _$cidadeAtom.reportRead();
    return super.cidade;
  }

  @override
  set cidade(Cidade value) {
    _$cidadeAtom.reportWrite(value, super.cidade, () {
      super.cidade = value;
    });
  }

  @override
  String toString() {
    return '''
cidade: ${cidade}
    ''';
  }
}
