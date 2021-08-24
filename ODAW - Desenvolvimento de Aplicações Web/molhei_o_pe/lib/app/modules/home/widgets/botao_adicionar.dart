import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class BotaoAdicionar extends StatelessWidget {
  final double bottom;
  final double left;
  final HomeController controller = Modular.get<HomeController>();

  BotaoAdicionar({@required this.bottom, @required this.left});

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.only(bottom: bottom, left: left),
      height: 50,
      width: 50,
      decoration: BoxDecoration(
        border: Border.all(color: ROXO_APP),
        borderRadius: BorderRadius.circular(100),
        color: ROXO_APP,
      ),
      child: IconButton(
        icon: Icon(
          Icons.add,
          color: Colors.white,
        ),
        onPressed: () {
          if (controller.user == null) {
            showDialog(
              context: context,
              builder: (BuildContext context) {
                return AlertDialog(
                  backgroundColor: ROXO_APP,
                  content: Text(
                    'Você precisa estar logado para registrar uma ocorrência!',
                    textAlign: TextAlign.center,
                    style: TextStyle(color: Colors.white),
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
          } else {
            controller.changeTelaAdicionar();
          }
        },
      ),
    );
  }
}
