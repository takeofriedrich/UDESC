import 'package:app_mobile/app/modules/home/comprar/comprar_controller.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

class CaixaSelecaoWidget extends StatelessWidget {
  final ComprarController controller = Modular.get<ComprarController>();
  final void Function() onTap;
  final String title;
  final Widget texto;

  CaixaSelecaoWidget({
    @required this.onTap,
    @required this.title,
    @required this.texto,
  });

  @override
  Widget build(BuildContext context) {
    return ContainerBorda(
      child: InkWell(
        onTap: onTap,
        child: Row(
          children: [
            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(title, style: TextStyle(fontSize: 20)),
                SizedBox(height: 10),
                texto,
              ],
            ),
          ],
        ),
      ),
    );
  }
}
