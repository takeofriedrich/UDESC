import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/aeroportos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:app_mobile/app/modules/home/comprar/trechos/interfaces/trechos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/interfaces/voos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/trecho.dart';
import 'package:flutter/src/material/time.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/voo.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';

part 'voos_postgres_repository.g.dart';

@Injectable()
class VoosPostgresRepository extends IVoosRepository {
  final PostgreSQLConnection connection =
      Modular.get<AppController>().connection;
  final String sqlFiltrar =
      'select * from filtrarVoos(@codcOrigem,@codcDestino,@data,@chegada);';
  final String sqlSelectVoo = 'select * from voos where codv = @codv';
  @override
  void dispose() {}

  @override
  Future<List<Voo>> listarVoos(Cidade origem, Cidade destino, DateTime data,
      TimeOfDay horarioSaida, TimeOfDay horarioChegada) async {
    DateTime saida = DateTime(data.year, data.month, data.day,
        horarioSaida.hour, horarioSaida.minute);
    DateTime chegada = DateTime(data.year, data.month, data.day,
        horarioChegada.hour, horarioChegada.minute);

    PostgreSQLResult resul =
        await connection.query(sqlFiltrar, substitutionValues: {
      'codcOrigem': origem.codC,
      'codcDestino': destino.codC,
      'data': saida,
      'chegada': chegada
    });

    List<Voo> voos = [];
    for (PostgreSQLResultRow row in resul) {
      await select(row.toColumnMap()['codv_']).then((value) {
        voos.add(value);
      });
    }
    return voos;
  }

  @override
  Future<Voo> select(int codv) async {
    PostgreSQLResult resul = await connection
        .query(sqlSelectVoo, substitutionValues: {'codv': codv});
    Voo voo = Voo();
    Map<String, dynamic> json = resul.first.toColumnMap();
    voo = Voo.fromJson(json);
    voo.origem = await Modular.get<IAeroportosRepository>()
        .buscarAeroporto(json['origem']);
    voo.destino = await Modular.get<IAeroportosRepository>()
        .buscarAeroporto(json['destino']);
    voo.trechos = await Modular.get<ITrechosRepository>().listarTrechos(codv);

    return voo;
  }
}
