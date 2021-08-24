import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'aeroportos_controller.dart';

class AeroportosPage extends StatefulWidget {
  const AeroportosPage({Key key}) : super(key: key);

  @override
  _AeroportosPageState createState() => _AeroportosPageState();
}

class _AeroportosPageState
    extends ModularState<AeroportosPage, AeroportosController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(controller.cidade.nome),
        centerTitle: true,
      ),
      body: Observer(
        builder: (BuildContext context) {
          return ListView.builder(
            itemBuilder: (BuildContext context, int index) {
              return ContainerBorda(
                child: Text(
                  controller.cidade.aeroportos[index].nome,
                  style: TextStyle(
                    fontSize: 18,
                  ),
                ),
              );
            },
            itemCount: controller.cidade.aeroportos.length,
          );
        },
      ),
    );
  }
}
