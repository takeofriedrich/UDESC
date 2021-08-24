import 'dart:async';
import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';
import 'package:flutter_map/plugin_api.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:location/location.dart';
import "package:latlong/latlong.dart";
import 'package:mobx/mobx.dart' as mobx;
import 'package:molhei_o_pe/app/modules/home/home_controller.dart';
import 'package:molhei_o_pe/app/modules/home/mapas/mapas_controller.dart';
import 'package:molhei_o_pe/app/modules/home/models/ocorrencia.dart';

class MapasPage extends StatefulWidget {
  @mobx.observable
  bool _loading = false;

  @mobx.computed
  set loading(value) => _loading = value;

  @mobx.computed
  get loading => _loading;
  @override
  _MapasPageState createState() => _MapasPageState();
}

class _MapasPageState extends State<MapasPage> {
  LocationData location;
  MapasController controller = Modular.get<MapasController>();
  List<Marker> markers = [];

  StreamSubscription<LocationData> inscricao;

  final mapController = MapController();

  @override
  void initState() {
    super.initState();
    inscricao = Location().onLocationChanged.listen((event) {
      setState(() {
        location = event;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return location != null
        ? Listener(
            onPointerSignal: (pointerSignal) {
              if (pointerSignal is PointerScrollEvent) {
                if (pointerSignal.scrollDelta.dy < 0) {
                  mapController.move(
                      mapController.center, mapController.zoom + 0.5);
                } else {
                  mapController.move(
                      mapController.center, mapController.zoom - 0.5);
                }
              }
            },
            child: Observer(
              builder: (context) => FlutterMap(
                mapController: mapController,
                options: MapOptions(
                  center: LatLng(location.latitude, location.longitude),
                  zoom: 15.0,
                  maxZoom: 25,
                  enableMultiFingerGestureRace: true,
                ),
                layers: [
                  TileLayerOptions(
                    urlTemplate:
                        "https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png",
                    subdomains: ['a', 'b', 'c'],
                  ),
                  MarkerLayerOptions(
                    markers: criarMarkers(controller.ocorrencias),
                  )
                ],
              ),
            ),
          )
        : Container();
  }

  List<Marker> criarMarkers(List<Ocorrencia> ocorrencias) {
    markers.clear();
    for (int i = 0; i < ocorrencias.length; i++) {
      markers.add(Marker(
        width: 30,
        height: 30,
        point: LatLng(
            ocorrencias[i].latLng.latitude, ocorrencias[i].latLng.longitude),
        builder: (context) {
          return GestureDetector(
            onTap: () {
              Modular.get<HomeController>()
                  .selecionarOcorrencia(ocorrencias[i]);
              Modular.get<HomeController>().changeTelaOcorrencia();
            },
            child: Icon(
              Icons.place,
              color: Colors.blue[900],
              size: 50,
            ),
          );
        },
      ));
    }
    if (location != null)
      markers.add(
        Marker(
          point: LatLng(location.latitude, location.longitude),
          builder: (context) {
            return Observer(
              builder: (BuildContext context) {
                return Modular.get<HomeController>().showLocation
                    ? Icon(
                        Icons.place,
                        color: Colors.red,
                        size: 50,
                      )
                    : Container();
              },
            );
          },
        ),
      );
    return markers;
  }

  @override
  void dispose() {
    super.dispose();
    inscricao.cancel();
  }
}
