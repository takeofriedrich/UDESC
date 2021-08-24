import 'package:app_mobile/app/modules/home/checkin/checkin_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/models/reserva.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:app_mobile/app/modules/utils/divisor_app.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';

class CheckinWidget extends StatefulWidget {
  final Reserva reserva;
  bool resumido = true;
  final CheckinController controller = Modular.get<CheckinController>();
  CheckinWidget({@required this.reserva});
  @override
  _CheckinWidgetState createState() => _CheckinWidgetState();
}

class _CheckinWidgetState extends State<CheckinWidget> {
  @override
  Widget build(BuildContext context) {
    return ContainerBorda(
      child: InkWell(
        onDoubleTap: () {
          setState(() {
            widget.resumido = !widget.resumido;
          });
        },
        child: widget.resumido
            ? Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    children: [
                      _text(
                        data(widget.reserva.data),
                      ),
                      Spacer(),
                      _text(
                        hora(widget.reserva.data),
                      ),
                      SizedBox(
                        width: 10,
                      ),
                      Icon(
                        widget.reserva.confirmada
                            ? Icons.check_circle_outline
                            : Icons.error_outline,
                        color: widget.reserva.confirmada
                            ? Colors.green
                            : Colors.red,
                      )
                    ],
                  ),
                  SizedBox(height: 10),
                  Row(
                    children: [
                      _text(
                        nomeOverflow(widget.reserva.origem.cidade.nome),
                      ),
                      SizedBox(width: 10),
                      _text('/'),
                      SizedBox(width: 10),
                      _text(
                        nomeOverflow(widget.reserva.destino.cidade.nome),
                      ),
                    ],
                  ),
                  DivisorApp(),
                  _textBold('Toque duplo para ver mais'),
                ],
              )
            : Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  _text('Origem:'),
                  SizedBox(
                    height: 10,
                  ),
                  Row(
                    children: [
                      _textBold('Cidade:'),
                      SizedBox(width: 10),
                      _text(nomeOverflow(widget.reserva.origem.cidade.nome)),
                    ],
                  ),
                  Row(
                    children: [
                      _textBold('Aeroporto:'),
                      SizedBox(width: 10),
                      _text(nomeOverflow(widget.reserva.origem.nome)),
                    ],
                  ),
                  DivisorApp(),
                  _text('Destino:'),
                  SizedBox(
                    height: 10,
                  ),
                  Row(
                    children: [
                      _textBold('Cidade:'),
                      SizedBox(width: 10),
                      _text(nomeOverflow(widget.reserva.destino.cidade.nome)),
                    ],
                  ),
                  Row(
                    children: [
                      _textBold('Aeroporto:'),
                      SizedBox(width: 10),
                      _text(nomeOverflow(widget.reserva.destino.nome)),
                    ],
                  ),
                  DivisorApp(),
                  Row(
                    children: [
                      _textBold('Data:'),
                      SizedBox(width: 10),
                      _text(
                        data(widget.reserva.data),
                      ),
                    ],
                  ),
                  Row(
                    children: [
                      _textBold('Hora:'),
                      SizedBox(width: 10),
                      _text(
                        hora(widget.reserva.data),
                      ),
                    ],
                  ),
                  DivisorApp(),
                  Row(
                    children: [
                      widget.reserva.confirmada
                          ? _text('Reserva já confirmada!')
                          : _textBold('Toque para fazer check-in'),
                      Spacer(),
                      Icon(
                        widget.reserva.confirmada
                            ? Icons.check_circle_outline
                            : Icons.error_outline,
                        color: widget.reserva.confirmada
                            ? Colors.green
                            : Colors.red,
                      )
                    ],
                  ),
                ],
              ),
        onTap: _fazerCheckin,
      ),
    );
  }

  _text(String text) {
    return Text(
      text,
      style: TextStyle(fontSize: 17),
    );
  }

  _textBold(String text) {
    return Text(
      text,
      style: TextStyle(fontSize: 17, fontWeight: FontWeight.bold),
    );
  }

  _fazerCheckin() {
    if (!widget.resumido && !widget.reserva.confirmada)
      widget.controller.realizarCheckin(widget.reserva);
  }
}
