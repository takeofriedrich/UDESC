import 'package:app_mobile/app/modules/home/comprar/widgets/selecionar_chegada_widget.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/selecionar_data_widget.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/selecionar_destino_widget.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/selecionar_origem_widget.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/selecionar_partida_widget.dart';
import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'comprar_controller.dart';

class ComprarPage extends StatefulWidget {
  final String title;
  const ComprarPage({Key key, this.title = "Comprar"}) : super(key: key);

  @override
  _ComprarPageState createState() => _ComprarPageState();
}

class _ComprarPageState extends ModularState<ComprarPage, ComprarController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
        centerTitle: true,
      ),
      body: ListView(
        //physics: NeverScrollableScrollPhysics(),
        children: <Widget>[
          SelecionarOrigemWidget(),
          SelecionarDestinoWidget(),
          SelecionarDataWidget(),
          SelecionarPartidaWidget(),
          SelecionarChegadaWidget(),
          Container(
            margin: EdgeInsets.symmetric(horizontal: 100, vertical: 20),
            child: BotaoApp(
              text: 'Filtrar',
              onPressed: () {
                controller.filtrar().catchError((error) =>
                    // exibirExcecao(context, error, 'Erro ao buscar voos'));
                    print(error));
              },
            ),
          ),
        ],
      ),
    );
  }
}
