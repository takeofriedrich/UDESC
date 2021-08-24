import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';

class BotaoRetorno extends StatelessWidget {
  final HomeController controller = Modular.get<HomeController>();
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 50,
      width: 80,
      margin: EdgeInsets.only(top: 65, left: 10),
      decoration: BoxDecoration(
        color: Colors.blue,
        border: Border.all(color: Colors.white, width: 3),
        borderRadius: BorderRadius.circular(35),
      ),
      child: InkWell(
        child: Icon(
          Icons.arrow_back,
          color: Colors.white,
        ),
        onTap: controller.telaSecundaria == TelaSecundaria.ADICIONAR
            ? controller.changeTelaAdicionar
            : controller.changeTelaOcorrencia,
      ),
    );
  }
}
