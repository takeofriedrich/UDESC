import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:hexcolor/hexcolor.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/botao.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class BarraPrincipal extends StatelessWidget {
  final BarraPrincipalLayout layout;
  BarraPrincipal({@required this.layout});
  @override
  Widget build(BuildContext context) {
    return Container(
      width: MediaQuery.of(context).size.width,
      height: 55,
      color: Colors.blue,
      child: Row(
        mainAxisAlignment: layout == BarraPrincipalLayout.NORMAL
            ? MainAxisAlignment.end
            : MainAxisAlignment.start,
        children: [
          Observer(
            builder: (context) => Botao(
                onTap: () {
                  Modular.get<HomeController>().changeTelaContato();
                },
                text: 'Contato',
                selectedAcima: Modular.get<HomeController>().telaSecundaria ==
                        TelaSecundaria.CONTATO
                    ? true
                    : false,
                margin: 50),
          ),
          layout == BarraPrincipalLayout.NORMAL ? Container() : Spacer(),
          Botao(
              onTap: Modular.get<HomeController>().loginGoogle,
              text: 'Login',
              margin: 50)
        ],
      ),
    );
  }
}

enum BarraPrincipalLayout { NORMAL, DIVIDIDO }
