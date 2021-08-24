import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class TelaOcorrencia extends StatelessWidget {
  final HomeController controller = Modular.get<HomeController>();

  @override
  Widget build(BuildContext context) {
    return Container(
        decoration: BoxDecoration(
          color: AZUL_APP,
        ),
        child: Stack(
          children: [
            ListView(
              children: [
                Container(
                  margin: EdgeInsets.only(
                      top: MediaQuery.of(context).size.width > 648 ? 120 : 80),
                  child: Center(
                      child: Text(
                    controller.ocorrenciaSelecionada.titulo,
                    style: TextStyle(fontSize: 20, color: Colors.white),
                  )),
                ),
                Container(
                  margin: EdgeInsets.only(top: 20, left: 30, right: 30),
                  child: Text(
                    controller.ocorrenciaSelecionada.comentario,
                    style: TextStyle(fontSize: 17, color: Colors.white),
                  ),
                ),
                Container(
                  margin: EdgeInsets.only(top: 20, left: 20, right: 20),
                  child: Image.network(
                    controller.ocorrenciaSelecionada.img,
                    fit: BoxFit.contain,
                  ),
                )
              ],
            ),
            Align(
              alignment: Alignment.bottomCenter,
              child: Container(
                margin: EdgeInsets.only(
                    bottom: MediaQuery.of(context).size.width <= 648 ? 50 : 70),
                child: ElevatedButton(
                  style: ElevatedButton.styleFrom(
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(35.0),
                    ),
                  ),
                  onPressed: () {},
                  child: Text(
                    'Denunciar',
                    style: TextStyle(fontSize: 20),
                  ),
                ),
              ),
            )
          ],
        ));
  }
}
