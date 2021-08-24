import 'package:cloud_firestore/cloud_firestore.dart';

class Ocorrencia {
  String uid;
  DateTime data;
  String titulo;
  String comentario;
  String img;
  GeoPoint latLng;

  Ocorrencia(
      {this.uid,
      this.data,
      this.titulo,
      this.comentario,
      this.img,
      this.latLng});

  Ocorrencia.fromJson(Map<String, dynamic> json) {
    if (json['hora'] != null) {
      Timestamp hora = json['hora'] ?? null;
      data = DateTime.fromMicrosecondsSinceEpoch(hora.microsecondsSinceEpoch);
    }
    latLng = json['local'] ?? null;
    titulo = json['titulo'] ?? null;
    comentario = json['comentario'] ?? null;
    img = json['img'] ?? null;
  }

  Map<String, dynamic> toJson() {
    Map<String, dynamic> json = {
      'titulo': titulo,
      'hora': data,
      'local': latLng,
      'comentario': comentario,
      'img': img
    };
    return json;
  }

  @override
  String toString() {
    return '$data - $titulo - $comentario - $img - $latLng';
  }
}
