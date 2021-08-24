import 'package:app_mobile/app/modules/home/comprar/comprar_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/caixa_selecao_widget.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

class SelecionarDataWidget extends StatelessWidget {
  final ComprarController controller = Modular.get<ComprarController>();

  @override
  Widget build(BuildContext context) {
    return CaixaSelecaoWidget(
        onTap: () {
          showDatePicker(
                  context: context,
                  initialDate: DateTime.now(),
                  firstDate: DateTime.now(),
                  lastDate: DateTime(2022, 1, 1))
              .then((value) => controller.definirData(value));
        },
        title: 'Data da viagem:',
        texto: Observer(
          builder: (BuildContext context) {
            return controller.data == null
                ? Text('Toque para selecionar')
                : Text(
                    '${normaliza2CasasDecimais(controller.data.day)}/${normaliza2CasasDecimais(controller.data.month)}/${normaliza2CasasDecimais(controller.data.year)}',
                  );
          },
        ));
  }
}
