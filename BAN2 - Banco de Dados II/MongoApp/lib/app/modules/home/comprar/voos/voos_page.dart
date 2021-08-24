import 'package:app_mobile/app/modules/home/comprar/voos/widgets/voos_widget.dart';
import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:app_mobile/app/modules/utils/consts.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'voos_controller.dart';

class VoosPage extends StatefulWidget {
  final String title;
  const VoosPage({Key key, this.title = "Voos"}) : super(key: key);

  @override
  _VoosPageState createState() => _VoosPageState();
}

class _VoosPageState extends ModularState<VoosPage, VoosController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
        centerTitle: true,
        leading: IconButton(
            icon: Icon(Icons.arrow_back), onPressed: controller.voltar),
      ),
      body: Column(
        children: [
          Flexible(
            flex: 7,
            child: ListView.builder(
              itemCount: controller.voos.length,
              itemBuilder: (BuildContext context, int index) {
                return Observer(
                  builder: (BuildContext context) {
                    return VoosWidget(
                      cor: index == controller.selecionado
                          ? COR_SELECIONADO
                          : Colors.white,
                      voo: controller.voos[index],
                      index: index,
                      controller: controller,
                    );
                  },
                );
              },
            ),
          ),
          Flexible(
            child: BotaoApp(
              text: 'Selecionar',
              onPressed: controller.confirmarSelecionado,
            ),
          ),
        ],
      ),
    );
  }
}
