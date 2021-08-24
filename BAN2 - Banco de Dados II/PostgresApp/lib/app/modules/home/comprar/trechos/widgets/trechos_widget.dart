import 'package:app_mobile/app/modules/home/comprar/trechos/trechos_controller.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:app_mobile/app/modules/utils/divisor_app.dart';
import 'package:app_mobile/app/modules/utils/espacamento_app.dart';
import 'package:app_mobile/app/modules/utils/texto_widgets_app.dart';
import 'package:app_mobile/app/modules/utils/titulo_widgets_app.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

class TrechosWidget extends StatelessWidget {
  final TrechosController controller = Modular.get<TrechosController>();
  final int index;
  TrechosWidget({@required this.index});
  @override
  Widget build(BuildContext context) {
    return ContainerBorda(
      child: InkWell(
        onTap: () {
          controller.onTap(index);
        },
        child: Column(
          children: [
            TituloWidgetsApp(titulo: 'Trecho ${index + 1}'),
            EspacamentoApp(),
            DivisorApp(),
            TituloWidgetsApp(titulo: 'Origem:'),
            EspacamentoApp(),
            TextosWidgetApp(
              texto: 'Cidade: ${controller.trechos[index].origem.cidade.nome}',
            ),
            TextosWidgetApp(
              texto: 'Aeroporto: ${controller.trechos[index].origem.nome}',
            ),
            DivisorApp(),
            TituloWidgetsApp(titulo: 'Destino:'),
            EspacamentoApp(),
            TextosWidgetApp(
              texto: 'Cidade: ${controller.trechos[index].destino.cidade.nome}',
            ),
            TextosWidgetApp(
              texto: 'Aeroporto: ${controller.trechos[index].destino.nome}',
            ),
            DivisorApp(),
            TituloWidgetsApp(titulo: 'Assento selecionado:'),
            EspacamentoApp(),
            Observer(
              builder: (BuildContext context) {
                return TextosWidgetApp(
                  texto: controller.assentosSelecionados[index] != null
                      ? controller.assentosSelecionados[index].toString()
                      : 'Toque para escolher',
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}
