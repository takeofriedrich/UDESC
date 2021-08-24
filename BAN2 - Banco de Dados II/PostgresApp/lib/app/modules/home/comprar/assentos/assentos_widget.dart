import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_controller.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

class AssentosWidget extends StatefulWidget {
  final int numero;

  AssentosWidget({@required this.numero});

  @override
  _AssentosWidgetState createState() => _AssentosWidgetState();
}

class _AssentosWidgetState extends State<AssentosWidget> {
  final AssentosController controller = Modular.get<AssentosController>();

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: () {
        setState(() {
          if (!controller.assentos[widget.numero + controller.inicial - 1])
            controller.selecionar(widget.numero);
        });
      },
      child: Column(
        children: [
          Row(
            children: [
              Observer(
                builder: (context) {
                  return Container(
                    height: 50,
                    width: 50,
                    margin: EdgeInsets.all(10),
                    padding: EdgeInsets.all(10),
                    child: Center(
                      child: Text(
                        '${widget.numero}',
                        style: TextStyle(
                          fontSize: 20,
                        ),
                      ),
                    ),
                    decoration: BoxDecoration(
                      border: Border.all(),
                      borderRadius: BorderRadius.circular(5),
                      color: controller.selecionado == widget.numero
                          ? Colors.yellow
                          : controller.assentos[
                                  widget.numero + controller.inicial - 1]
                              ? Colors.red
                              : Colors.green,
                    ),
                  );
                },
              ),
            ],
          ),
        ],
      ),
    );
  }
}
