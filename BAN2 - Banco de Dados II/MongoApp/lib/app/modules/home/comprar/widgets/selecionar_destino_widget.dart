import 'package:app_mobile/app/modules/home/comprar/comprar_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/caixa_selecao_widget.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

class SelecionarDestinoWidget extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return CaixaSelecaoWidget(
      onTap: () {
        Modular.to.pushNamed('/home/comprar/destino');
      },
      title: 'Cidade de destino:',
      texto: Observer(
        builder: (BuildContext context) {
          return Text(Modular.get<ComprarController>().destino == null
              ? 'Toque para selecionar a cidade de destino'
              : Modular.get<ComprarController>().destino.nome);
        },
      ),
    );
  }
}
