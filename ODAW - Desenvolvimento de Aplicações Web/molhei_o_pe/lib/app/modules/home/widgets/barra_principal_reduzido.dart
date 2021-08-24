import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class BarraPrincipalReduzido extends StatelessWidget {
  final void Function() onTapMenu;
  final HomeController controller = Modular.get<HomeController>();

  BarraPrincipalReduzido({@required this.onTapMenu});

  @override
  Widget build(BuildContext context) {
    return Container(
      width: MediaQuery.of(context).size.width,
      height: 55,
      color: ROXO_APP,
      child: Row(
        children: [
          Flexible(
            flex: 1,
            child: Container(
              margin: EdgeInsets.only(left: 10),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.start,
                children: [
                  Observer(
                    builder: (BuildContext context) {
                      return InkWell(
                        child: Icon(
                          controller.telaSecundaria == TelaSecundaria.NENHUMA
                              ? Icons.menu
                              : Icons.arrow_back,
                          color: Colors.white,
                        ),
                        onTap:
                            controller.telaSecundaria == TelaSecundaria.NENHUMA
                                ? onTapMenu
                                : controller.backMapa,
                      );
                    },
                  ),
                ],
              ),
            ),
          ),
          Flexible(
            flex: 10,
            child: Container(
              margin: EdgeInsets.only(bottom: 5),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Image.asset('images/logo.png'),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
