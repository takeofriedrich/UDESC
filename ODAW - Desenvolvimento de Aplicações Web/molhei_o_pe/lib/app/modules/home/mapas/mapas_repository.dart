import 'dart:async';
import 'dart:io';
import 'dart:typed_data';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/home/models/ocorrencia.dart';

import 'package:molhei_o_pe/app/modules/utils/functions.dart';

class MapasRepository {
  StreamSubscription<DocumentSnapshot> inscricao;

  void buscarRegiao(void Function(DocumentSnapshot) onData) async {
    DocumentReference ocorrenciasDia =
        FirebaseFirestore.instance.collection('ocorrencias').doc(data());
    if (!(await ocorrenciasDia.get()).exists) {
      await ocorrenciasDia.set({});
    }
    inscricao = ocorrenciasDia.snapshots().listen(onData);
  }

  Future<String> buscarFoto(String folder, String file) async {
    print(folder);
    print(file);
    Reference image = FirebaseStorage.instance
        .ref('gs://molheiope-34cd3.appspot.com')
        .child(folder)
        .child(file);
    return image.getDownloadURL();
  }

  Future<String> salvarFoto(Uint8List foto, User usuario) async {
    Reference reference = FirebaseStorage.instance
        .ref('gs://molheiope-34cd3.appspot.com/${data()}/${usuario.uid}.jpeg');
    await reference.putData(foto, SettableMetadata(contentType: 'image/jpeg'));
    return await reference.getDownloadURL();
  }

  Future<bool> salvarOcorrencia(Ocorrencia ocorrencia, User usuario) async {
    DocumentReference ocorrenciasDia =
        FirebaseFirestore.instance.collection('ocorrencias').doc(data());
    if (!(await ocorrenciasDia.get()).exists) {
      await ocorrenciasDia.set({});
    }

    int numero = await numeroOcorrencias(usuario);
    print(numero);

    if (numero < 5) {
      Uint8List bytes =
          await Modular.get<HomeController>().pickedFile.readAsBytes();
      String link = await salvarFoto(bytes, usuario);
      ocorrencia.img = link;
      await ocorrenciasDia.update({usuario.uid: ocorrencia.toJson()});
      incrementar(usuario);
      return true;
    } else {
      return false;
    }
  }

  Future<int> numeroOcorrencias(User usuario) async {
    DocumentReference users =
        FirebaseFirestore.instance.collection('users').doc(usuario.email);
    DocumentSnapshot snapshot = await users.get();
    int ocorrencias = snapshot.data()['ocorrencias'];
    return ocorrencias;
  }

  void incrementar(User usuario) async {
    await FirebaseFirestore.instance
        .collection('users')
        .doc(usuario.email)
        .update({'ocorrencias': FieldValue.increment(1)});
  }

  void cancel() {
    inscricao.cancel();
  }

  String data() {
    DateTime data = DateTime.now();
    return '${data.year}-${toString2Casas(data.month)}-${toString2Casas(data.day - 2)}';
  }
}
