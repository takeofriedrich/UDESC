// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'home_controller.dart';

// **************************************************************************
// StoreGenerator
// **************************************************************************

// ignore_for_file: non_constant_identifier_names, unnecessary_brace_in_string_interps, unnecessary_lambdas, prefer_expression_function_bodies, lines_longer_than_80_chars, avoid_as, avoid_annotating_with_dynamic

mixin _$HomeController on _HomeControllerBase, Store {
  final _$userAtom = Atom(name: '_HomeControllerBase.user');

  @override
  User get user {
    _$userAtom.reportRead();
    return super.user;
  }

  @override
  set user(User value) {
    _$userAtom.reportWrite(value, super.user, () {
      super.user = value;
    });
  }

  final _$pickedFileAtom = Atom(name: '_HomeControllerBase.pickedFile');

  @override
  PickedFile get pickedFile {
    _$pickedFileAtom.reportRead();
    return super.pickedFile;
  }

  @override
  set pickedFile(PickedFile value) {
    _$pickedFileAtom.reportWrite(value, super.pickedFile, () {
      super.pickedFile = value;
    });
  }

  final _$ocorrenciaSelecionadaAtom =
      Atom(name: '_HomeControllerBase.ocorrenciaSelecionada');

  @override
  Ocorrencia get ocorrenciaSelecionada {
    _$ocorrenciaSelecionadaAtom.reportRead();
    return super.ocorrenciaSelecionada;
  }

  @override
  set ocorrenciaSelecionada(Ocorrencia value) {
    _$ocorrenciaSelecionadaAtom.reportWrite(value, super.ocorrenciaSelecionada,
        () {
      super.ocorrenciaSelecionada = value;
    });
  }

  final _$telaSecundariaAtom = Atom(name: '_HomeControllerBase.telaSecundaria');

  @override
  TelaSecundaria get telaSecundaria {
    _$telaSecundariaAtom.reportRead();
    return super.telaSecundaria;
  }

  @override
  set telaSecundaria(TelaSecundaria value) {
    _$telaSecundariaAtom.reportWrite(value, super.telaSecundaria, () {
      super.telaSecundaria = value;
    });
  }

  final _$showLocationAtom = Atom(name: '_HomeControllerBase.showLocation');

  @override
  bool get showLocation {
    _$showLocationAtom.reportRead();
    return super.showLocation;
  }

  @override
  set showLocation(bool value) {
    _$showLocationAtom.reportWrite(value, super.showLocation, () {
      super.showLocation = value;
    });
  }

  final _$salvandoAtom = Atom(name: '_HomeControllerBase.salvando');

  @override
  bool get salvando {
    _$salvandoAtom.reportRead();
    return super.salvando;
  }

  @override
  set salvando(bool value) {
    _$salvandoAtom.reportWrite(value, super.salvando, () {
      super.salvando = value;
    });
  }

  final _$numeroOcorrenciasAtom =
      Atom(name: '_HomeControllerBase.numeroOcorrencias');

  @override
  int get numeroOcorrencias {
    _$numeroOcorrenciasAtom.reportRead();
    return super.numeroOcorrencias;
  }

  @override
  set numeroOcorrencias(int value) {
    _$numeroOcorrenciasAtom.reportWrite(value, super.numeroOcorrencias, () {
      super.numeroOcorrencias = value;
    });
  }

  final _$valueAtom = Atom(name: '_HomeControllerBase.value');

  @override
  int get value {
    _$valueAtom.reportRead();
    return super.value;
  }

  @override
  set value(int value) {
    _$valueAtom.reportWrite(value, super.value, () {
      super.value = value;
    });
  }

  final _$_HomeControllerBaseActionController =
      ActionController(name: '_HomeControllerBase');

  @override
  dynamic changeTelaOcorrencia() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.changeTelaOcorrencia');
    try {
      return super.changeTelaOcorrencia();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic selecionarOcorrencia(Ocorrencia ocorrencia) {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.selecionarOcorrencia');
    try {
      return super.selecionarOcorrencia(ocorrencia);
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic changeTelaAdicionar() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.changeTelaAdicionar');
    try {
      return super.changeTelaAdicionar();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic changeTelaSobre() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.changeTelaSobre');
    try {
      return super.changeTelaSobre();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic changeTelaContato() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.changeTelaContato');
    try {
      return super.changeTelaContato();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic backMapa() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.backMapa');
    try {
      return super.backMapa();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic changeShowLocation() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.changeShowLocation');
    try {
      return super.changeShowLocation();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic visualizarImagem(PickedFile file) {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.visualizarImagem');
    try {
      return super.visualizarImagem(file);
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic voltarAdicionar() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.voltarAdicionar');
    try {
      return super.voltarAdicionar();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  void getNumeroOcorrenciasDisponiveis() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.getNumeroOcorrenciasDisponiveis');
    try {
      return super.getNumeroOcorrenciasDisponiveis();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  dynamic nroOcorrencias(dynamic value) {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.nroOcorrencias');
    try {
      return super.nroOcorrencias(value);
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  void increment() {
    final _$actionInfo = _$_HomeControllerBaseActionController.startAction(
        name: '_HomeControllerBase.increment');
    try {
      return super.increment();
    } finally {
      _$_HomeControllerBaseActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
user: ${user},
pickedFile: ${pickedFile},
ocorrenciaSelecionada: ${ocorrenciaSelecionada},
telaSecundaria: ${telaSecundaria},
showLocation: ${showLocation},
salvando: ${salvando},
numeroOcorrencias: ${numeroOcorrencias},
value: ${value}
    ''';
  }
}
