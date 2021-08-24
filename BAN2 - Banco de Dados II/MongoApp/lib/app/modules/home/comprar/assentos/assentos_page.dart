import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_widget.dart';
import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'assentos_controller.dart';

class AssentosPage extends StatefulWidget {
  final String title;
  const AssentosPage({Key key, this.title = "Assentos"}) : super(key: key);

  @override
  _AssentosPageState createState() => _AssentosPageState();
}

class _AssentosPageState
    extends ModularState<AssentosPage, AssentosController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Container(
        margin: EdgeInsets.all(20),
        child: Column(
          children: <Widget>[
            Flexible(
                flex: 2,
                child: Column(
                  children: [
                    Text(
                      'Selecione uma poltrona:',
                      style: TextStyle(fontSize: 20),
                    ),
                    SizedBox(
                      height: 20,
                    ),
                    Row(
                      children: [
                        Container(
                          decoration: BoxDecoration(
                            color: Colors.red,
                            border: Border.all(),
                            borderRadius: BorderRadius.circular(15),
                          ),
                          padding: EdgeInsets.all(5),
                        ),
                        SizedBox(
                          width: 20,
                        ),
                        Container(
                          child: Text(
                            'Ocupadas',
                            style: TextStyle(
                              fontSize: 17,
                            ),
                          ),
                        ),
                      ],
                    ),
                    Row(
                      children: [
                        Container(
                          decoration: BoxDecoration(
                            color: Colors.green,
                            border: Border.all(),
                            borderRadius: BorderRadius.circular(15),
                          ),
                          padding: EdgeInsets.all(5),
                        ),
                        SizedBox(
                          width: 20,
                        ),
                        Container(
                          child: Text(
                            'Disponíveis',
                            style: TextStyle(
                              fontSize: 17,
                            ),
                          ),
                        ),
                      ],
                    ),
                  ],
                )),
            Flexible(
              flex: 7,
              child: ListView.builder(
                itemBuilder: (BuildContext context, int index) {
                  return Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      AssentosWidget(
                        numero: (4 * index) + 1,
                      ),
                      AssentosWidget(
                        numero: (4 * index) + 2,
                      ),
                      Spacer(),
                      AssentosWidget(
                        numero: (4 * index) + 3,
                      ),
                      AssentosWidget(
                        numero: (4 * index) + 4,
                      ),
                    ],
                  );
                },
                itemCount: (controller.assentos.length / 4).round(),
              ),
            ),
            Flexible(
              child: BotaoApp(
                  text: 'Confirmar',
                  onPressed: () {
                    try {
                      controller.salvar();
                    } catch (e) {
                      exibirExcecao(context, e, 'Erro ao salvar');
                    }
                  }),
            ),
          ],
        ),
      ),
    );
  }
}
