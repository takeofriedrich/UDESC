import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:app_mobile/app/modules/utils/caixa_input.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'realizar_controller.dart';

class RealizarPage extends StatefulWidget {
  final String title;
  const RealizarPage({Key key, this.title = "Realizar Check-in"})
      : super(key: key);

  @override
  _RealizarPageState createState() => _RealizarPageState();
}

class _RealizarPageState
    extends ModularState<RealizarPage, RealizarController> {
  //use 'controller' variable to access controller

  TextEditingController inputController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.purple[300],
      appBar: AppBar(
        title: Text(widget.title),
        centerTitle: true,
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: <Widget>[
          Row(
            children: [
              Container(
                padding: EdgeInsets.symmetric(horizontal: 30),
                child: Text(
                  'Digite o código:',
                  style: TextStyle(
                    fontSize: 20,
                    color: Colors.white,
                  ),
                ),
              ),
            ],
          ),
          Container(
            padding: EdgeInsets.symmetric(horizontal: 20, vertical: 20),
            child: CaixaInput(
                controller: inputController,
                password: false,
                hint: 'XXXXXXXXXX'),
          ),
          BotaoApp(
            text: 'Realizar',
            onPressed: controller.efetuar,
          ),
        ],
      ),
    );
  }
}
