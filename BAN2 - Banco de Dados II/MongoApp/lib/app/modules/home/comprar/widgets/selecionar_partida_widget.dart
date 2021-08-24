import 'package:app_mobile/app/modules/home/comprar/comprar_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/widgets/caixa_selecao_widget.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

class SelecionarPartidaWidget extends StatelessWidget {
  final ComprarController controller = Modular.get<ComprarController>();

  @override
  Widget build(BuildContext context) {
    return CaixaSelecaoWidget(
        onTap: () {
          showTimePicker(
                  context: context,
                  initialTime: TimeOfDay(hour: 00, minute: 00))
              .then((value) => controller.definirHorarioSaida(value));
        },
        title: 'Horário de partida da viagem:',
        texto: Observer(
          builder: (BuildContext context) {
            return controller.horarioSaida == null
                ? Text('Toque para selecionar')
                : Text(
                    '${normaliza2CasasDecimais(controller.horarioSaida.hour)}h${normaliza2CasasDecimais(controller.horarioSaida.minute)}');
          },
        ));
  }
}
