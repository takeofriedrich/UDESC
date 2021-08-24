import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:app_mobile/app/modules/utils/consts.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'selecionar_origem_controller.dart';

class SelecionarOrigemPage extends StatefulWidget {
  final String title;
  const SelecionarOrigemPage({Key key, this.title = "Selecionar Origem"})
      : super(key: key);

  @override
  _SelecionarOrigemPageState createState() => _SelecionarOrigemPageState();
}

class _SelecionarOrigemPageState
    extends ModularState<SelecionarOrigemPage, SelecionarOrigemController> {
  //use 'controller' variable to access controller

  bool loading = true;

  @override
  void initState() {
    super.initState();
    controller.buscarCidades().whenComplete(() {
      setState(() {
        loading = false;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
        centerTitle: true,
      ),
      body: Column(
        children: <Widget>[
          Flexible(
            child: loading
                ? Center(
                    child: CircularProgressIndicator(),
                  )
                : Observer(
                    builder: (BuildContext context) {
                      return controller.cidadesDisponiveis.isEmpty
                          ? Center(
                              child: ListView(
                                shrinkWrap: true,
                                children: [
                                  Row(
                                    mainAxisAlignment: MainAxisAlignment.center,
                                    children: [
                                      Text('Não há cidades na lista'),
                                    ],
                                  ),
                                ],
                              ),
                            )
                          : ListView.builder(
                              itemBuilder: (BuildContext context, int index) {
                                return Observer(
                                  builder: (context) {
                                    return InkWell(
                                      onTap: () {
                                        controller.selectIndex(index);
                                      },
                                      child: ContainerBorda(
                                          color: controller.index == index
                                              ? COR_SELECIONADO
                                              : Colors.white,
                                          child: Row(
                                            children: [
                                              Text(controller
                                                  .cidadesDisponiveis[index]
                                                  .nome),
                                            ],
                                          )),
                                    );
                                  },
                                );
                              },
                              itemCount: controller.cidadesDisponiveis.length,
                            );
                    },
                  ),
            flex: 8,
          ),
          Flexible(
              child: BotaoApp(
            text: 'Selecionar origem',
            onPressed: controller.definirCidade,
          )),
        ],
      ),
    );
  }
}
