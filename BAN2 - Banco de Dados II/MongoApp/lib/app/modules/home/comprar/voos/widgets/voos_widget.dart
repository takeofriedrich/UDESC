import 'package:app_mobile/app/modules/home/comprar/voos/models/voo.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/voos_controller.dart';
import 'package:app_mobile/app/modules/utils/divisor_app.dart';
import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:app_mobile/app/modules/utils/espacamento_app.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:app_mobile/app/modules/utils/texto_widgets_app.dart';
import 'package:app_mobile/app/modules/utils/titulo_widgets_app.dart';
import 'package:flutter/material.dart';

class VoosWidget extends StatefulWidget {
  final Voo voo;
  final int index;
  final VoosController controller;
  final Color cor;

  VoosWidget(
      {@required this.voo,
      @required this.index,
      @required this.controller,
      @required this.cor});

  @override
  _VoosWidgetState createState() => _VoosWidgetState();
}

class _VoosWidgetState extends State<VoosWidget> {
  bool resumida = true;

  @override
  Widget build(BuildContext context) {
    return resumida
        ? ContainerBorda(
            color: widget.cor,
            child: InkWell(
              child: Container(
                child: Column(
                  children: [
                    TituloWidgetsApp(
                        titulo:
                            '${nomeOverflow(widget.voo.origem.cidade.nome)} - ${nomeOverflow(widget.voo.destino.cidade.nome)}'),
                    TextosWidgetApp(
                        texto:
                            '${normaliza2CasasDecimais(widget.voo.data.day)}/${normaliza2CasasDecimais(widget.voo.data.month)}/${normaliza2CasasDecimais(widget.voo.data.year)} : ${normaliza2CasasDecimais(widget.voo.data.hour)}h${normaliza2CasasDecimais(widget.voo.data.minute)}'),
                  ],
                ),
              ),
              onDoubleTap: () {
                setState(() {
                  resumida = !resumida;
                });
              },
              onTap: () {
                widget.controller.selecionarVoo(widget.index);
              },
            ),
          )
        : ContainerBorda(
            color: widget.cor,
            child: InkWell(
              onDoubleTap: () {
                setState(() {
                  resumida = !resumida;
                });
              },
              child: Column(
                children: [
                  TituloWidgetsApp(titulo: 'Origem:'),
                  EspacamentoApp(),
                  TextosWidgetApp(
                      texto:
                          '${nomeOverflow(widget.voo.origem.cidade.nome)} - ${nomeOverflow(widget.voo.origem.nome)}'),
                  DivisorApp(),
                  TituloWidgetsApp(titulo: 'Destino:'),
                  EspacamentoApp(),
                  TextosWidgetApp(
                      texto:
                          '${nomeOverflow(widget.voo.destino.cidade.nome)} - ${nomeOverflow(widget.voo.destino.nome)}'),
                  DivisorApp(),
                  TituloWidgetsApp(titulo: 'Data:'),
                  EspacamentoApp(),
                  TextosWidgetApp(
                      texto:
                          '${normaliza2CasasDecimais(widget.voo.data.day)}/${normaliza2CasasDecimais(widget.voo.data.month)}/${normaliza2CasasDecimais(widget.voo.data.year)}'),
                  DivisorApp(),
                  TituloWidgetsApp(titulo: 'Hora:'),
                  EspacamentoApp(),
                  TextosWidgetApp(
                      texto:
                          '${normaliza2CasasDecimais(widget.voo.data.hour)}h${normaliza2CasasDecimais(widget.voo.data.minute)}'),
                  DivisorApp(),
                  TituloWidgetsApp(titulo: 'Nº de Trechos:'),
                  TextosWidgetApp(
                      texto: '${_numeroDeTrechos(widget.voo.trechos.length)}'),
                ],
              ),
            ),
          );
  }

  _numeroDeTrechos(int quantidade) {
    return quantidade > 0 ? '$quantidade' : 'Viagem direta';
  }
}
