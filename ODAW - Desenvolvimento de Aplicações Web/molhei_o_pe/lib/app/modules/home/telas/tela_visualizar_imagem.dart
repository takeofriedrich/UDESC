import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class TelaVisualizarImagem extends StatefulWidget {
  @override
  _TelaVisualizarImagemState createState() => _TelaVisualizarImagemState();
}

class _TelaVisualizarImagemState extends State<TelaVisualizarImagem> {
  final HomeController controller = Modular.get<HomeController>();

  @override
  Widget build(BuildContext context) {
    return Container(
      color: AZUL_APP,
      child: Stack(
        children: [
          Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              InkWell(
                onTap: controller.getImage,
                child: Stack(
                  alignment: Alignment.center,
                  children: [
                    Observer(
                      builder: (BuildContext context) {
                        return Container(
                          height: MediaQuery.of(context).size.height,
                          width: MediaQuery.of(context).size.width,
                          child: controller.pickedFile != null
                              ? kIsWeb
                                  ? Image.network(
                                      controller.pickedFile.path,
                                      fit: BoxFit.contain,
                                    )
                                  : Image.file(File(controller.pickedFile.path))
                              : Container(),
                        );
                      },
                    ),
                    Text(
                      'Toque para alterar a imagem',
                      style: TextStyle(
                        color: Colors.white,
                      ),
                    ),
                  ],
                ),
              ),
            ],
          ),
          Container(
            alignment: Alignment.bottomCenter,
            margin: EdgeInsets.only(bottom: 100),
            child: ElevatedButton(
              style: ElevatedButton.styleFrom(
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(35.0),
                ),
              ),
              onPressed: controller.voltarAdicionar,
              child: Text(
                'Confirmar',
                style: TextStyle(fontSize: 20),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
