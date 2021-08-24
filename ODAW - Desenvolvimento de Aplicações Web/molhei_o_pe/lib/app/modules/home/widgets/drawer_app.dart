import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:flutter_signin_button/button_list.dart';
import 'package:flutter_signin_button/button_view.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/home/home_page.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class DrawerApp extends StatelessWidget {
  final HomeController controller = Modular.get<HomeController>();
  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: Container(
        color: ROXO_APP,
        child: ListView(
          children: [
            Observer(
              builder: (context) => Column(
                children: [
                  controller.user != null
                      ? DrawerHeader(
                          child: Column(
                            children: [
                              Expanded(
                                child: CircleAvatar(
                                  backgroundImage:
                                      NetworkImage(controller.user.photoURL),
                                ),
                              ),
                              Container(
                                padding: EdgeInsets.symmetric(horizontal: 5),
                                child: Row(
                                  children: [
                                    Text(
                                      'Cadastros:',
                                      style: TextStyle(
                                        color: Colors.white,
                                        fontSize: 17,
                                      ),
                                    ),
                                    Spacer(),
                                    Observer(
                                      builder: (context) => Text(
                                        controller.numeroOcorrencias.isNegative
                                            ? '0'
                                            : '${controller.numeroOcorrencias}',
                                        style: TextStyle(
                                            color: Colors.white, fontSize: 17),
                                      ),
                                    ),
                                  ],
                                ),
                              ),
                              // Divider(
                              //   thickness: 2,
                              //   color: Colors.white,
                              // ),
                            ],
                          ),
                        )
                      : Container(),
                ],
              ),
            ),
            _botao('Mapa'),
            _botao('Sobre', () {
              controller.changeTelaSobre();
              Navigator.pop(context);
            }),
            _botao('Contato', () {
              controller.changeTelaContato();
              Navigator.pop(context);
            }),
            _botao('Facebook'),
            _botao('Twitter'),
            _botao('Youtube'),
            Observer(
              builder: (context) => controller.user == null
                  ? Center(
                      child: SignInButton(Buttons.Google,
                          onPressed: controller.loginGoogle),
                    )
                  : Container(),
            ),
            _botao('Copyright'),
          ],
        ),
      ),
    );
  }

  _botao(String text, [void Function() onTap]) {
    return Center(
      child: InkWell(
        onTap: onTap != null ? onTap : () {},
        child: Container(
          margin: EdgeInsets.all(25),
          child: Text(
            text,
            style: TextStyle(color: Colors.white, fontSize: 20),
          ),
        ),
      ),
    );
  }
}
