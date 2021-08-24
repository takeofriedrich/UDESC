import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';

import 'interfaces/aeroportos_repository_interface.dart';

part 'aeroportos_postgres_repository.g.dart';

@Injectable()
class AeroportosPostgresRepository implements IAeroportosRepository {
  String sqlSelect = 'select * from  buscarAeroportosCidade(@codC)';
  String sqlSelect1 =
      'select codap as codap_, nome as nome_, codc as codc_ from aeroportos where codap = @coda limit 1';
  PostgreSQLConnection connection = Modular.get<AppController>().connection;

  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<List<Aeroporto>> buscarAeroportos(int codC) async {
    List<Aeroporto> aeroportos = [];
    PostgreSQLResult resul =
        await connection.query(sqlSelect, substitutionValues: {'codC': codC});
    resul.forEach((element) {
      aeroportos.add(Aeroporto.fromMap(element.toColumnMap()));
    });
    return aeroportos;
  }

  Future<Aeroporto> buscarAeroporto(int codA) async {
    return await connection.query(sqlSelect1,
        substitutionValues: {'coda': codA}).then((value) async {
      Map<String, dynamic> jsonAero = value.first.toColumnMap();
      Aeroporto a = Aeroporto.fromMap(jsonAero);
      a.cidade = await Modular.get<ICidadesRepository>()
          .buscarCidade(jsonAero['codc_']);
      return a;
    });
  }
}
