import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'perfil_controller.dart';

class PerfilPage extends StatefulWidget {
  final String title;
  const PerfilPage({Key key, this.title = "Perfil"}) : super(key: key);

  @override
  _PerfilPageState createState() => _PerfilPageState();
}

class _PerfilPageState extends ModularState<PerfilPage, PerfilController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
        centerTitle: true,
      ),
      body: Column(
        children: [
          Row(
            children: [
              Container(
                margin: EdgeInsets.only(top: 10),
                padding: EdgeInsets.symmetric(horizontal: 20, vertical: 10),
                child: Text(
                  'Nome do Passageiro:',
                  style: TextStyle(
                    fontSize: 20,
                  ),
                ),
              ),
            ],
          ),
          Row(
            children: [
              Container(
                padding: EdgeInsets.symmetric(horizontal: 20),
                child: Text(
                  Modular.get<AppController>().usuario.nome,
                  style: TextStyle(
                    fontSize: 16,
                  ),
                ),
              ),
            ],
          ),
          Spacer(),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                margin: EdgeInsets.all(30),
                child: BotaoApp(
                  onPressed: controller.logout,
                  text: 'Desconectar',
                ),
              ),
            ],
          ),
        ],
      ),
    );
  }
}
