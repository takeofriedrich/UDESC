import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class BotaoLocalizacao extends StatelessWidget {
  final double bottom;
  final double right;
  final HomeController controller = Modular.get<HomeController>();
  BotaoLocalizacao({@required this.bottom, @required this.right});
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.only(bottom: bottom, right: right),
      height: 50,
      width: 50,
      decoration: BoxDecoration(
        border: Border.all(color: ROXO_APP),
        borderRadius: BorderRadius.circular(100),
        color: ROXO_APP,
      ),
      child: IconButton(
        icon: Icon(
          Icons.place,
          color: Colors.white,
        ),
        onPressed: controller.changeShowLocation,
      ),
    );
  }
}
