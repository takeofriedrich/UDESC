import 'package:app_mobile/app/modules/home/comprar/trechos/widgets/trechos_widget.dart';
import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'trechos_controller.dart';

class TrechosPage extends StatefulWidget {
  final String title;
  const TrechosPage({Key key, this.title = "Trechos"}) : super(key: key);

  @override
  _TrechosPageState createState() => _TrechosPageState();
}

class _TrechosPageState extends ModularState<TrechosPage, TrechosController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Column(
        children: <Widget>[
          Flexible(
            flex: 7,
            child: ListView.builder(
              itemBuilder: (BuildContext context, int index) {
                return TrechosWidget(index: index);
              },
              itemCount: controller.trechos.length,
            ),
          ),
          Flexible(
            child: BotaoApp(
              text: 'Fechar reserva',
              onPressed: exibirConfirmacao,
            ),
          ),
        ],
      ),
    );
  }

  exibirConfirmacao() {
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text('Realizar compra'),
          content: SingleChildScrollView(
            child: Text('Deseja confirmar a compra do assentos?'),
          ),
          actions: [
            TextButton(
                onPressed: controller.realizarReservas, child: Text('Ok')),
            TextButton(
                onPressed: () => Navigator.pop(context),
                child: Text('Cancelar')),
          ],
        );
      },
    );
  }
}
