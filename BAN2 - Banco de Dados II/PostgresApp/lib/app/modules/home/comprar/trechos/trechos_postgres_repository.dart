import 'package:app_mobile/app/modules/home/cidades/interfaces/aeroportos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:app_mobile/app/modules/home/comprar/trechos/interfaces/trechos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/trecho.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';
import 'package:postgres/postgres.dart';

import '../../../../app_controller.dart';

part 'trechos_postgres_repository.g.dart';

@Injectable()
class TrechosPostgresRepository extends ITrechosRepository {
  //dispose will be called automatically
  final PostgreSQLConnection connection =
      Modular.get<AppController>().connection;
  final String sqlSelect = 'select * from buscarTrechosVooCompleto(@codV);';
  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<List<Trecho>> listarTrechos(int codV) async {
    return connection
        .query(sqlSelect, substitutionValues: {'codV': codV}).then((value) {
      List<Trecho> trechos = [];
      value.forEach((element) async {
        Map<String, dynamic> json = element.toColumnMap();
        Trecho t = Trecho.fromJson(json);
        t.origem = await Modular.get<IAeroportosRepository>()
            .buscarAeroporto(json['origem_']);
        t.destino = await Modular.get<IAeroportosRepository>()
            .buscarAeroporto(json['destino_']);
        trechos.add(t);
      });
      return trechos;
    });
  }
}
