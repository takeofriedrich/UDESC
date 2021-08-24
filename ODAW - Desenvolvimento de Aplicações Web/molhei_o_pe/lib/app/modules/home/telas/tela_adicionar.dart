import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:image_picker/image_picker.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';

import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class TelaAdicionar extends StatefulWidget {
  @override
  _TelaAdicionarState createState() => _TelaAdicionarState();
}

class _TelaAdicionarState extends State<TelaAdicionar> {
  final picker = ImagePicker();

  HomeController controller = Modular.get<HomeController>();

  @override
  Widget build(BuildContext context) {
    return Container(
      color: AZUL_APP,
      child: Observer(
        builder: (BuildContext context) {
          return controller.salvando
              ? Center(
                  child: CircularProgressIndicator(
                    backgroundColor: Colors.white,
                  ),
                )
              : ListView(
                  children: [
                    Container(
                      margin: EdgeInsets.only(
                          top: MediaQuery.of(context).size.width > 648
                              ? 100
                              : 80,
                          bottom: 20),
                      child: Center(
                        child: Text(
                          'Cadastrar ocorrência',
                          textAlign: TextAlign.center,
                          style: TextStyle(
                            fontSize: MediaQuery.of(context).size.width > 399
                                ? 25
                                : 17,
                            color: Colors.white,
                          ),
                        ),
                      ),
                    ),
                    Container(
                      margin: EdgeInsets.only(top: 15, left: 50, right: 50),
                      child: TextFormField(
                        enableSuggestions: false,
                        autocorrect: false,
                        obscureText: false,
                        controller: controller.titulo,
                        maxLength: 100,
                        decoration: InputDecoration(
                          counterStyle: TextStyle(color: Colors.white),
                          filled: true,
                          fillColor: Colors.white,
                          hintText: 'Digite um titulo para a ocorrência',
                          focusedBorder: OutlineInputBorder(
                            borderSide: BorderSide(color: Colors.white),
                            borderRadius: BorderRadius.circular(20),
                          ),
                          enabledBorder: UnderlineInputBorder(
                            borderSide: BorderSide(color: Colors.white),
                            borderRadius: BorderRadius.circular(20),
                          ),
                        ),
                        style: TextStyle(
                          backgroundColor: Colors.white,
                          fontSize: 17,
                        ),
                      ),
                    ),
                    Container(
                      margin: EdgeInsets.only(top: 15, left: 50, right: 50),
                      child: TextFormField(
                        controller: controller.comentario,
                        enableSuggestions: false,
                        autocorrect: false,
                        obscureText: false,
                        minLines: 15,
                        maxLines: 35,
                        maxLength: 500,
                        decoration: InputDecoration(
                          counterStyle: TextStyle(color: Colors.white),
                          filled: true,
                          fillColor: Colors.white,
                          hintText: 'Descreva o que aconteceu',
                          focusedBorder: OutlineInputBorder(
                            borderSide: BorderSide(color: Colors.white),
                            borderRadius: BorderRadius.circular(20),
                          ),
                          enabledBorder: UnderlineInputBorder(
                            borderSide: BorderSide(color: Colors.white),
                            borderRadius: BorderRadius.circular(20),
                          ),
                        ),
                        style: TextStyle(
                          backgroundColor: Colors.white,
                          fontSize: 17,
                        ),
                      ),
                    ),
                    Container(
                      margin: EdgeInsets.only(bottom: 80),
                      child: Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            margin: EdgeInsets.only(top: 20, right: 20),
                            child: ElevatedButton(
                              style: ElevatedButton.styleFrom(
                                shape: RoundedRectangleBorder(
                                  borderRadius: BorderRadius.circular(35.0),
                                ),
                              ),
                              onPressed: () async {
                                if (controller.pickedFile == null) {
                                  exibirErroFotoNull('Selecione uma foto!');
                                } else if (controller.titulo.text.isEmpty) {
                                  exibirErroFotoNull('Escolha um titulo!');
                                } else if (controller.comentario.text.isEmpty) {
                                  exibirErroFotoNull(
                                      'Descreva o ocorrido no comentário!');
                                } else {
                                  bool result =
                                      await controller.salvarOcorrencia();
                                  if (!result) {
                                    exibirErroFotoNull(
                                        'Número máximo de ocorrências atingido!');
                                    controller.salvando = false;
                                  }
                                }
                              },
                              child: Text(
                                'Salvar',
                                style: TextStyle(fontSize: 20),
                              ),
                            ),
                          ),
                          Observer(
                            builder: (BuildContext context) {
                              return controller.pickedFile == null
                                  ? Container(
                                      margin:
                                          EdgeInsets.only(top: 20, right: 20),
                                      child: ElevatedButton(
                                        style: ElevatedButton.styleFrom(
                                          shape: RoundedRectangleBorder(
                                            borderRadius:
                                                BorderRadius.circular(35.0),
                                          ),
                                        ),
                                        onPressed: controller.getImage,
                                        child: Text(
                                          'Escolher Foto',
                                          style: TextStyle(fontSize: 20),
                                        ),
                                      ),
                                    )
                                  : Container();
                            },
                          ),
                          Observer(
                            builder: (BuildContext context) {
                              return controller.pickedFile != null
                                  ? Container(
                                      margin:
                                          EdgeInsets.only(top: 20, right: 20),
                                      child: ElevatedButton(
                                        onPressed: () =>
                                            controller.visualizarImagem(
                                                controller.pickedFile),
                                        style: ElevatedButton.styleFrom(
                                          shape: RoundedRectangleBorder(
                                            borderRadius:
                                                BorderRadius.circular(35.0),
                                          ),
                                        ),
                                        child: Container(
                                          child: Text(
                                            'Visualizar Imagem',
                                            style: TextStyle(fontSize: 20),
                                          ),
                                        ),
                                      ),
                                    )
                                  : Container();
                            },
                          ),
                        ],
                      ),
                    ),
                  ],
                );
        },
      ),
    );
  }

  exibirErroFotoNull(String text) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          backgroundColor: ROXO_APP,
          content: Text(
            text,
            style: TextStyle(color: Colors.white),
            textAlign: TextAlign.center,
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: Container(
                child: Text(
                  'Confirmar',
                  style: TextStyle(color: Colors.white),
                ),
                margin: EdgeInsets.only(right: 5),
              ),
            )
          ],
        );
      },
    );
  }
}
