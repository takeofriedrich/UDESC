import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/botao.dart';

class BarraInferior extends StatefulWidget {
  @override
  _BarraInferiorState createState() => _BarraInferiorState();
}

class _BarraInferiorState extends State<BarraInferior> {
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 55,
      width: MediaQuery.of(context).size.width,
      decoration: BoxDecoration(
        color: Colors.blue,
        border: Border.all(color: Colors.blue, style: BorderStyle.none),
        borderRadius: BorderRadius.only(
          topLeft: Radius.circular(60),
          topRight: Radius.circular(60),
        ),
      ),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Observer(
            builder: (context) => Botao(
                onTap: () {
                  Modular.get<HomeController>().changeTelaSobre();
                },
                text: 'Sobre',
                selected: Modular.get<HomeController>().telaSecundaria ==
                    TelaSecundaria.SOBRE,
                margin: 30),
          ),
          Observer(
            builder: (context) => Botao(
                onTap: () {
                  Modular.get<HomeController>().backMapa();
                },
                selected: Modular.get<HomeController>().telaSecundaria ==
                    TelaSecundaria.NENHUMA,
                text: 'Mapa',
                margin: 30),
          ),
          Botao(onTap: () {}, text: 'Facebook', margin: 30),
          Botao(onTap: () {}, text: 'Twitter', margin: 30),
          Botao(onTap: () {}, text: 'Copyright', margin: 30),
        ],
      ),
    );
  }
}
