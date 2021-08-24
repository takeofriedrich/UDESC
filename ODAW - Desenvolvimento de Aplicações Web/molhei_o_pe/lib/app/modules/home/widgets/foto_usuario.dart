import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';

class FotoUsuario extends StatelessWidget {
  HomeController controller = Modular.get<HomeController>();
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.only(bottom: 30, left: 40),
      height: 150,
      width: 150,
      decoration: BoxDecoration(
        border: Border.all(color: Colors.purple),
        borderRadius: BorderRadius.circular(100),
        color: Colors.purple,
      ),
      child: CircleAvatar(
        backgroundImage: NetworkImage(controller.user.photoURL),
      ),
    );
  }
}
