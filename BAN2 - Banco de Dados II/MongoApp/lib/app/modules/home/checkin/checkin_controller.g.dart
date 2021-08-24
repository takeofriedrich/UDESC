// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'checkin_controller.dart';

// **************************************************************************
// InjectionGenerator
// **************************************************************************

final $CheckinController = BindInject(
  (i) => CheckinController(),
  singleton: true,
  lazy: true,
);

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$CheckinController on _CheckinControllerBase, Store {
  final _$reservasAtom = Atom(name: '_CheckinControllerBase.reservas');

  @override
  List<Reserva> get reservas {
    _$reservasAtom.reportRead();
    return super.reservas;
  }

  @override
  set reservas(List<Reserva> value) {
    _$reservasAtom.reportWrite(value, super.reservas, () {
      super.reservas = value;
    });
  }

  final _$_CheckinControllerBaseActionController =
      ActionController(name: '_CheckinControllerBase');

  @override
  Future<void> buscarReservas() {
    final _$actionInfo = _$_CheckinControllerBaseActionController.startAction(
        name: '_CheckinControllerBase.buscarReservas');
    try {
      return super.buscarReservas();
    } finally {
      _$_CheckinControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
reservas: ${reservas}
    ''';
  }
}
