import 'dart:convert';
import 'dart:html';
import 'dart:typed_data';

import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/cupertino.dart';
import 'package:image_picker/image_picker.dart';
import 'package:location/location.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/login_repository.dart';
import 'package:molhei_o_pe/app/modules/home/mapas/mapas_repository.dart';
import 'package:molhei_o_pe/app/modules/home/models/ocorrencia.dart';

part 'home_controller.g.dart';

@Injectable()
class HomeController = _HomeControllerBase with _$HomeController;

abstract class _HomeControllerBase with Store {
  @observable
  User user;

  @observable
  PickedFile pickedFile;

  @observable
  Ocorrencia ocorrenciaSelecionada;

  @observable
  TelaSecundaria telaSecundaria = TelaSecundaria.NENHUMA;

  @observable
  bool showLocation = false;

  @observable
  bool salvando = false;

  @observable
  int numeroOcorrencias = -1;

  final picker = ImagePicker();

  TextEditingController titulo = TextEditingController();
  TextEditingController comentario = TextEditingController();

  LoginRepository repository = Modular.get<LoginRepository>();
  MapasRepository mapasRepository = Modular.get<MapasRepository>();

  _HomeControllerBase() {
    FirebaseAuth.instance.authStateChanges().listen((User value) {
      if (user == null) {
        user = null;
      }
    });
  }

  loginGoogle() {
    repository.signInWithGoogle().then((value) {
      user = value.user;
      repository.loginFirestore(value.user);
      getNumeroOcorrenciasDisponiveis();
    });
  }

  @action
  changeTelaOcorrencia() {
    telaSecundaria = telaSecundaria == TelaSecundaria.NENHUMA
        ? TelaSecundaria.OCORRENCIA
        : TelaSecundaria.NENHUMA;
  }

  @action
  selecionarOcorrencia(Ocorrencia ocorrencia) {
    this.ocorrenciaSelecionada = ocorrencia;
  }

  @action
  changeTelaAdicionar() {
    telaSecundaria = telaSecundaria == TelaSecundaria.NENHUMA
        ? TelaSecundaria.ADICIONAR
        : TelaSecundaria.NENHUMA;
  }

  @action
  changeTelaSobre() {
    telaSecundaria = telaSecundaria == TelaSecundaria.NENHUMA ||
            telaSecundaria == TelaSecundaria.CONTATO
        ? TelaSecundaria.SOBRE
        : TelaSecundaria.NENHUMA;
  }

  @action
  changeTelaContato() {
    telaSecundaria = telaSecundaria == TelaSecundaria.NENHUMA ||
            telaSecundaria == TelaSecundaria.SOBRE
        ? TelaSecundaria.CONTATO
        : TelaSecundaria.NENHUMA;
  }

  @action
  backMapa() {
    telaSecundaria = TelaSecundaria.NENHUMA;
  }

  @action
  changeShowLocation() {
    showLocation = !showLocation;
  }

  @action
  visualizarImagem(PickedFile file) {
    this.pickedFile = file;
    telaSecundaria = TelaSecundaria.VISUALIZAR;
  }

  @action
  voltarAdicionar() {
    telaSecundaria = TelaSecundaria.ADICIONAR;
  }

  Future getImage() async {
    final pickedFile =
        await picker.getImage(source: ImageSource.camera, imageQuality: 25);
    this.pickedFile = pickedFile;
  }

  Future<bool> salvarOcorrencia() async {
    salvando = true;
    bool retorno = false;
    LocationData location = await Location().getLocation();
    GeoPoint locate = GeoPoint(location.latitude, location.longitude);
    Ocorrencia ocorrencia = Ocorrencia(
      data: DateTime.now(),
      titulo: titulo.text,
      comentario: comentario.text,
      latLng: locate,
    );
    retorno =
        await Modular.get<MapasRepository>().salvarOcorrencia(ocorrencia, user);
    titulo.clear();
    comentario.clear();
    pickedFile = null;
    salvando = false;
    changeTelaAdicionar();
    getNumeroOcorrenciasDisponiveis();
    return retorno;
  }

  @action
  void getNumeroOcorrenciasDisponiveis() {
    Modular.get<MapasRepository>().numeroOcorrencias(user).then((value) {
      nroOcorrencias(value);
    });
  }

  @action
  nroOcorrencias(value) {
    numeroOcorrencias = value;
    print(numeroOcorrencias);
  }

  @observable
  int value = 0;

  @action
  void increment() {
    value++;
  }
}

enum TelaSecundaria {
  NENHUMA,
  ADICIONAR,
  VISUALIZAR,
  OCORRENCIA,
  SOBRE,
  CONTATO,
}
