import 'package:flutter_test/flutter_test.dart';
import 'package:mockito/mockito.dart';
import 'package:dio/dio.dart';

import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_mongo_repository.dart';

class MockClient extends Mock implements Dio {}

void main() {
  AssentosMongoRepository repository;
  // MockClient client;

  setUp(() {
    // repository = AssentosMongoRepository();
    // client = MockClient();
  });

  group('AssentosMongoRepository Test', () {
    //  test("First Test", () {
    //    expect(repository, isInstanceOf<AssentosMongoRepository>());
    //  });

    test('returns a Post if the http call completes successfully', () async {
      //    when(client.get('https://jsonplaceholder.typicode.com/posts/1'))
      //        .thenAnswer((_) async =>
      //            Response(data: {'title': 'Test'}, statusCode: 200));
      //    Map<String, dynamic> data = await repository.fetchPost(client);
      //    expect(data['title'], 'Test');
    });
  });
}
